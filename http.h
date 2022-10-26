

#define SERVO_1      12
#define SERVO_2      13

#define SERVO_STEP   5

Servo servoN1;
Servo servoN2;
Servo servo1;
Servo servo2;


#define PART_BOUNDARY "123456789000000000000987654321"

int servo1Pos = 90;
int servo2Pos = 90;

static const char* _STREAM_CONTENT_TYPE = "multipart/x-mixed-replace;boundary=" PART_BOUNDARY;
static const char* _STREAM_BOUNDARY = "\r\n--" PART_BOUNDARY "\r\n";
static const char* _STREAM_PART = "Content-Type: image/jpeg\r\nContent-Length: %u\r\n\r\n";

httpd_handle_t camera_httpd = NULL;
httpd_handle_t stream_httpd = NULL;

static esp_err_t index_handler(httpd_req_t *req){
  httpd_resp_set_type(req, "text/html");
  return httpd_resp_send(req, (const char *)INDEX_HTML, strlen(INDEX_HTML));
}

static esp_err_t stream_handler(httpd_req_t *req){
  camera_fb_t * fb = NULL;
  esp_err_t res = ESP_OK;
  size_t _jpg_buf_len = 0;
  uint8_t * _jpg_buf = NULL;
  char * part_buf[64];

  res = httpd_resp_set_type(req, _STREAM_CONTENT_TYPE);
  if(res != ESP_OK){
    return res;
  }

  while(true){
    fb = esp_camera_fb_get();
    if (!fb) {
      Serial.println("Camera capture failed");
      res = ESP_FAIL;
    } else {
      if(fb->width > 400){
        if(fb->format != PIXFORMAT_JPEG){
          bool jpeg_converted = frame2jpg(fb, 80, &_jpg_buf, &_jpg_buf_len);
          esp_camera_fb_return(fb);
          fb = NULL;
          if(!jpeg_converted){
            Serial.println("JPEG compression failed");
            res = ESP_FAIL;
          }
        } else {
          _jpg_buf_len = fb->len;
          _jpg_buf = fb->buf;
        }
      }
    }
    if(res == ESP_OK){
      size_t hlen = snprintf((char *)part_buf, 64, _STREAM_PART, _jpg_buf_len);
      res = httpd_resp_send_chunk(req, (const char *)part_buf, hlen);
    }
    if(res == ESP_OK){
      res = httpd_resp_send_chunk(req, (const char *)_jpg_buf, _jpg_buf_len);
    }
    if(res == ESP_OK){
      res = httpd_resp_send_chunk(req, _STREAM_BOUNDARY, strlen(_STREAM_BOUNDARY));
    }
    if(fb){
      esp_camera_fb_return(fb);
      fb = NULL;
      _jpg_buf = NULL;
    } else if(_jpg_buf){
      free(_jpg_buf);
      _jpg_buf = NULL;
    }
    if(res != ESP_OK){
      break;
    }
    //Serial.printf("MJPG: %uB\n",(uint32_t)(_jpg_buf_len));
  }
  return res;
}

static esp_err_t cmd_handler(httpd_req_t *req){
  char*  buf;
  size_t buf_len;
  char variable[32] = {0,};
  char pos1[32] = {0,};
  char pos2[32] = {0,};
  
  buf_len = httpd_req_get_url_query_len(req) + 1;
  if (buf_len > 1) {
    buf = (char*)malloc(buf_len);
    if(!buf){
      httpd_resp_send_500(req);
      return ESP_FAIL;
    }
    if (httpd_req_get_url_query_str(req, buf, buf_len) == ESP_OK) {
      if (httpd_query_key_value(buf, "pos1", pos1, sizeof(pos1)) == ESP_OK) {
      } else {
        free(buf);
        httpd_resp_send_404(req);
        return ESP_FAIL;
      }

      if (httpd_query_key_value(buf, "pos2", pos2, sizeof(pos2)) == ESP_OK) {
      } else {
        free(buf);
        httpd_resp_send_404(req);
        return ESP_FAIL;
      }
      
    } else {
      free(buf);
      httpd_resp_send_404(req);
      return ESP_FAIL;
    }
    free(buf);

  } else {
    httpd_resp_send_404(req);
    return ESP_FAIL;
  }

  sensor_t * s = esp_camera_sensor_get();
  //flip the camera vertically
  //s->set_vflip(s, 1);          // 0 = disable , 1 = enable
  // mirror effect
  //s->set_hmirror(s, 1);          // 0 = disable , 1 = enable

  int res = 0;


  servo1.write( atoi(pos1)); 
  servo2.write( atoi(pos2)); 


        Serial.println("servo1 "+ String(pos1));
        Serial.println("servo2 "+ String(pos2));

    /*
  if(!strcmp(variable, "up")) {
    if(servo1Pos <= 170) {
      servo1Pos += 5;
      servo1.write(servo1Pos);
    }
    Serial.println(servo1Pos);
    Serial.println("Up");
  }
  else if(!strcmp(variable, "left")) {
    if(servo2Pos <= 170) {
      servo2Pos += 5;
      servo2.write(servo2Pos);
    }
    Serial.println(servo2Pos);
    Serial.println("Left");
  }
  else if(!strcmp(variable, "right")) {
    if(servo2Pos >= 5) {
      servo2Pos -= 5;
      servo2.write(servo2Pos);
    }
    Serial.println(servo2Pos);
    Serial.println("Right");
  }
  else if(!strcmp(variable, "down")) {
    if(servo1Pos >= 5) {
      servo1Pos -= 5;
      servo1.write(servo1Pos);
    }
    Serial.println(servo1Pos);
    Serial.println("Down");
  }
  else {
    res = -1;
  }
  */

  if(res){
    return httpd_resp_send_500(req);
  }

  httpd_resp_set_hdr(req, "Access-Control-Allow-Origin", "*");
  return httpd_resp_send(req, NULL, 0);
}
