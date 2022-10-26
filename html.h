
static const char PROGMEM INDEX_HTML[] = R"rawliteral(

<html>
  <head>
    <title>Rover Control</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <script>
      let StickStatus={xPosition:0,yPosition:0,x:0,y:0,cardinalDirection:"C"};var JoyStick=function(t,e,i){var o=void 0===(e=e||{}).title?"joystick":e.title,n=void 0===e.width?0:e.width,a=void 0===e.height?0:e.height,r=void 0===e.internalFillColor?"#00AA00":e.internalFillColor,c=void 0===e.internalLineWidth?2:e.internalLineWidth,s=void 0===e.internalStrokeColor?"#003300":e.internalStrokeColor,d=void 0===e.externalLineWidth?2:e.externalLineWidth,u=void 0===e.externalStrokeColor?"#008000":e.externalStrokeColor,h=void 0===e.autoReturnToCenter||e.autoReturnToCenter;i=i||function(t){};var S=document.getElementById(t);S.style.touchAction="none";var f=document.createElement("canvas");f.id=o,0===n&&(n=S.clientWidth),0===a&&(a=S.clientHeight),f.width=n,f.height=a,S.appendChild(f);var l=f.getContext("2d"),k=0,g=2*Math.PI,x=(f.width-(f.width/2+10))/2,v=x+5,P=x+30,m=f.width/2,C=f.height/2,p=f.width/10,y=-1*p,w=f.height/10,L=-1*w,F=m,E=C;function W(){l.beginPath(),l.arc(m,C,P,0,g,!1),l.lineWidth=d,l.strokeStyle=u,l.stroke()}function T(){l.beginPath(),F<x&&(F=v),F+x>f.width&&(F=f.width-v),E<x&&(E=v),E+x>f.height&&(E=f.height-v),l.arc(F,E,x,0,g,!1);var t=l.createRadialGradient(m,C,5,m,C,200);t.addColorStop(0,r),t.addColorStop(1,s),l.fillStyle=t,l.fill(),l.lineWidth=c,l.strokeStyle=s,l.stroke()}function D(){let t="",e=F-m,i=E-C;return i>=L&&i<=w&&(t="C"),i<L&&(t="N"),i>w&&(t="S"),e<y&&("C"===t?t="W":t+="W"),e>p&&("C"===t?t="E":t+="E"),t}"ontouchstart"in document.documentElement?(f.addEventListener("touchstart",function(t){k=1},!1),document.addEventListener("touchmove",function(t){1===k&&t.targetTouches[0].target===f&&(F=t.targetTouches[0].pageX,E=t.targetTouches[0].pageY,"BODY"===f.offsetParent.tagName.toUpperCase()?(F-=f.offsetLeft,E-=f.offsetTop):(F-=f.offsetParent.offsetLeft,E-=f.offsetParent.offsetTop),l.clearRect(0,0,f.width,f.height),W(),T(),StickStatus.xPosition=F,StickStatus.yPosition=E,StickStatus.x=((F-m)/v*100).toFixed(),StickStatus.y=((E-C)/v*100*-1).toFixed(),StickStatus.cardinalDirection=D(),i(StickStatus))},!1),document.addEventListener("touchend",function(t){k=0,h&&(F=m,E=C);l.clearRect(0,0,f.width,f.height),W(),T(),StickStatus.xPosition=F,StickStatus.yPosition=E,StickStatus.x=((F-m)/v*100).toFixed(),StickStatus.y=((E-C)/v*100*-1).toFixed(),StickStatus.cardinalDirection=D(),i(StickStatus)},!1)):(f.addEventListener("mousedown",function(t){k=1},!1),document.addEventListener("mousemove",function(t){1===k&&(F=t.pageX,E=t.pageY,"BODY"===f.offsetParent.tagName.toUpperCase()?(F-=f.offsetLeft,E-=f.offsetTop):(F-=f.offsetParent.offsetLeft,E-=f.offsetParent.offsetTop),l.clearRect(0,0,f.width,f.height),W(),T(),StickStatus.xPosition=F,StickStatus.yPosition=E,StickStatus.x=((F-m)/v*100).toFixed(),StickStatus.y=((E-C)/v*100*-1).toFixed(),StickStatus.cardinalDirection=D(),i(StickStatus))},!1),document.addEventListener("mouseup",function(t){k=0,h&&(F=m,E=C);l.clearRect(0,0,f.width,f.height),W(),T(),StickStatus.xPosition=F,StickStatus.yPosition=E,StickStatus.x=((F-m)/v*100).toFixed(),StickStatus.y=((E-C)/v*100*-1).toFixed(),StickStatus.cardinalDirection=D(),i(StickStatus)},!1)),W(),T(),this.GetWidth=function(){return f.width},this.GetHeight=function(){return f.height},this.GetPosX=function(){return F},this.GetPosY=function(){return E},this.GetX=function(){return((F-m)/v*100).toFixed()},this.GetY=function(){return((E-C)/v*100*-1).toFixed()},this.GetDir=function(){return D()}};
    </script>
    <style>
      body { font-family: Arial; text-align: center; margin:0px auto; padding-top: 30px;}
      table { margin-left: auto; margin-right: auto; }
      td { padding: 8 px; }
      .button {
        background-color: #2f4468;
        border: none;
        color: white;
        padding: 10px 20px;
        text-align: center;
        text-decoration: none;
        display: inline-block;
        font-size: 18px;
        margin: 6px 3px;
        cursor: pointer;
        -webkit-touch-callout: none;
        -webkit-user-select: none;
        -khtml-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
        -webkit-tap-highlight-color: rgba(0,0,0,0);
      }
      img {  width: auto ;
        max-width: 100% ;
        height: auto ; 
      }
      .columnLateral
{
  float: left;
  width: 15%;
  min-width: 300px;
}
.columnCetral
{
  float: left;
  width: 70%;
  min-width: 300px;
}
@media screen and (min-width: 320px) and (max-width: 767px) and (orientation: portrait) {
  html {
    transform: rotate(-90deg);
    transform-origin: left top;
    width: 100vh;
    height: 100vw;
    overflow-x: hidden;
    position: absolute;
    top: 100%;
    left: 0;
  }
}
#joy2Div
{
  width:200px;
  height:200px;
  margin:50px
}
#joystick
{
  border: 1px solid #FF0000;
}
#joystick2
{
  border: 1px solid #0000FF;
}
    </style>
  </head>
  <body>
    <h3>Camera</h1>
    <img src="" id="photo" style="width:640px;height:480px" >
    <!-- Example of FIXED or ABSOLUTE position -->
<div style="width: 200px; height: 200px; margin: 30px; position: fixed; top: 40px; right: 1px; touch-action: none;">
 <div style="
    right: auto;
"> Rover Control  
 </div>
    <div id="joy3Div" style="width:200px;height:200px;margin:30px;position:fixed;top:40px;right:1px;"></div>
</div>
    <div style="position:fixed;bottom:10px;right:1px;">
      Posizione X:<input id="joy3PosizioneX" type="text" /><br />
      Posizione Y:<input id="joy3PosizioneY" type="text" /><br />
      Direzione:<input id="joy3Direzione" type="text" /><br />
      X :<input id="joy3X" type="text" /></br>
      Y :<input id="joy3Y" type="text" />
    </div>
    
    <table style="display:none">
      <tr><td colspan="3" align="center"><button class="button" onmousedown="toggleCheckbox('up');" ontouchstart="toggleCheckbox('up');">Forward</button></td></tr>
      <tr><td align="center"><button class="button" onmousedown="toggleCheckbox('left');" ontouchstart="toggleCheckbox('left');">Turn Left</button></td><td align="center"></td><td align="center"><button class="button" onmousedown="toggleCheckbox('right');" ontouchstart="toggleCheckbox('right');">Turn Right</button></td></tr>
      <tr><td colspan="3" align="center"><button class="button" onmousedown="toggleCheckbox('down');" ontouchstart="toggleCheckbox('down');">Backward</button></td></tr>                   
    </table>
   <script>
    function toggleCheckbox(x) {
     var xhr = new XMLHttpRequest();
     xhr.open("GET", "/action?go=" + x, true);
     xhr.send();
   }
   
   

   
   window.onload = function(){
    
    document.getElementById("photo").src = window.location.href.slice(0, -1) + ":81/stream";
   
var joy3Param = { "title": "joystick3" };
//var Joy3 = new JoyStick('joy3Div', joy3Param);
var lservo1 = 0;
var lservo2 = 0;

var Joy3 = new JoyStick('joy3Div', 
{
    // The ID of canvas element
    title: 'joystick',
    // width/height
    width: undefined,
    height: undefined,
    // Internal color of Stick
    internalFillColor: '#00AA00',
    // Border width of Stick
    internalLineWidth: 2,
    // Border color of Stick
    internalStrokeColor: '#003300',
    // External reference circonference width
    externalLineWidth: 2,
    //External reference circonference color
    externalStrokeColor: '#008000',
    // Sets the behavior of the stick
    autoReturnToCenter: true
    
}, function(stickData) {
    joy3PosizioneX.value = stickData.xPosition;
    joy3PosizioneX.value = stickData.yPosition;
    joy3Direzione.value = stickData.cardinalDirection;
    joy3X.value = stickData.x;
    joy3Y.value = stickData.y;
    
    request_to_web(stickData);
});


var joy3IinputPosX = document.getElementById("joy3PosizioneX");
var joy3InputPosY = document.getElementById("joy3PosizioneY");
var joy3Direzione = document.getElementById("joy3Direzione");
var joy3X = document.getElementById("joy3X");
var joy3Y = document.getElementById("joy3Y");




   function request_to_web(stickData){
   
     var servo1 = 0;
     var servo2 = 0;
     var servox1 = 0;
     var servox2 = 0;
     var servo1x = 0;
     var servo2x = 0;    
     var step = 3;
     var mult1 = 1; 
     var mult2 = 1;
     
       
      if (Joy3.GetY() < 0 ){ 
        mult1 = -1
        mult2 = -1;
      }else{
        mult1 = 1;
        mult2 = 1;
      }
     // Axiss Y
     if (Math.abs(stickData.y) <= 20  ){

     
     }else{
      servo1 = parseInt(Math.abs(stickData.y) / 20);
      servo2 = parseInt(Math.abs(stickData.y) / 20) ;
      remy = Math.abs(stickData.y) % 20;
      if (remy > 0 ){
        servo1 = servo1;
        servo2 = servo2;
     }
     }
      // Axiss X
      if (Math.abs(stickData.x) <= 20 ){
     }else{
      remy = Math.abs(stickData.x) % 20;
      if (stickData.x > 20 ){
      //servo1x = Math.abs(parseInt(Joy3.GetX() / 20));
        servo2x = Math.abs(parseInt(stickData.x/ 20));
        if (remy > 0){
          servo2x = servo2x;
        }
         if ( Math.abs(stickData.y) <= 20 /* servo2 == 0 */ ){
           servo1x = ( servo2x * step ) * -1;
           servo2x = servo1x;
           mult2 = mult1 * -1;
         }else{
           servo2x = parseInt(servo2x / 4 * (servo2 * step));
         }
        }
        else if (stickData.x <= -20){

      //servo1x = parseInt(Joy3.GetX() / 20);
        servo1x = Math.abs(parseInt(stickData.x / 20));
        if (remy > 0){
          servo1x = servo1x ;
        }
        
         if (Math.abs(stickData.y) <= 20  /*servo2 ==0  */){
             //    console.log("less than 20");
           servo2x = ( servo1x * step ) * -1;
           servo1x = servo2x;
           mult1 =  mult1 * -1;
          // console.log("servo2x=",servo2x," servo1x",servo1x,"mult=",mult2 );
         }else{
           servo1x = parseInt(servo1x / 4 * (servo1 * step));
         }
        }
        
      }
      
     servox1 = 90 + ( ( servo1 * step)   -  servo1x   )      * mult1  ;
     servox2 = 90 + ( ( servo2 * step)  - servo2x  )   * ( mult2 / -1) ;
     
     if (lservo1 != servox1 || lservo2 != servox2) {
       var xhr = new XMLHttpRequest();
     xhr.open("GET", "/action?pos1=" + servox1+"&pos2="+servox2, true);
     xhr.send();
     
      lservo1 = servox1;
      lservo2 = servox2;
     }
      

   
   }
   



//setInterval(function(){ //joy3IinputPosX.value=Joy3.GetPosX(); }, 50);
//setInterval(function(){ //joy3InputPosY.value=Joy3.GetPosY(); }, 50);
//setInterval(function(){ //joy3Direzione.value=Joy3.GetDir(); }, 50);
//setInterval(function(){ joy3X.value=Joy3.GetX(); }, 50);
//setInterval(function(){ joy3Y.value=Joy3.GetY(); }, 50);
//setInterval(function(){  
/*
  
  var xhr = new XMLHttpRequest();
     var servo1 = 0;
     var servo2 = 0;
     var servox1 = 0;
     var servox2 = 0;
     var servo1x = 0;
     var servo2x = 0;    
     var step = 3;
     var mult1 = 1; 
     var mult2 = 1;
     
       
      if (Joy3.GetY() < 0 ){ 
        mult1 = -1
        mult2 = -1;
      }else{
        mult1 = 1;
        mult2 = 1;
      }
     // Axiss Y
     if (Math.abs(Joy3.GetY()) <= 20  ){
     }else{
      servo1 = parseInt(Math.abs(Joy3.GetY()) / 20);
      servo2 = parseInt(Math.abs(Joy3.GetY()) / 20) ;
      remy = Math.abs(Joy3.GetY()) % 20;
      if (remy > 0 ){
        servo1 = servo1;
        servo2 = servo2;
     }
     }
      // Axiss X
      if (Math.abs(Joy3.GetX()) <= 20 ){
     }else{
      remy = Math.abs(Joy3.GetX()) % 20;
      if (Joy3.GetX() > 20 ){
      //servo1x = Math.abs(parseInt(Joy3.GetX() / 20));
        servo2x = Math.abs(parseInt(Joy3.GetX() / 20));
        if (remy > 0){
          servo2x = servo2x;
        }
         if (servo2 ==0 ){
           servo1x = ( servo2x * step ) * -1;
           servo2x = servo1x;
           mult2 = mult1 * -1;
         }else{
           servo2x = parseInt(servo2x / 4 * (servo2 * step));
         }
        }
        else if (Joy3.GetX() < -20){
      //servo1x = parseInt(Joy3.GetX() / 20);
        servo1x = Math.abs(parseInt(Joy3.GetX() / 20));
        if (remy > 0){
          servo1x = servo1x ;
        }
         if (servo2 ==0 ){
           servo2x = ( servo1x * step ) * -1;
           servo1x = servo2x;
           mult1 =  -1;
         }else{
           servo1x = parseInt(servo1x / 4 * (servo1 * step));
         }
        }
        
      }
     servox1 = 90 + ( ( servo1 * step)   -  servo1x   )      * mult1  ;
     servox2 = 90 + ( ( servo2 * step)  - servo2x  )   * ( mult2 / -1) ;
     
     if (lservo1 != servox1 || lservo2 != servox2) {
     xhr.open("GET", "/action?pos1=" + servox1+"&pos2="+servox2, true);
     xhr.send();
     
      lservo1 = servox1;
      lservo2 = servox2;
     }
      
      */
//     } , 100000000);
   }
  </script>
  </body>
</html>

)rawliteral";
