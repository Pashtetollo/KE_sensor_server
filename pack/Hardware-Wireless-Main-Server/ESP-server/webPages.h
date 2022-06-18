#pragma once

const char index_html[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>GreenHouse</title>
</head>
<body id="myBody" style="overflow: hidden;">
<script>
  var mySVG =`<svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" style="margin:auto;background:#ffffff;display:block;z-index:1;position:relative" width="1536" height="754" preserveAspectRatio="xMidYMid" viewBox="0 0 1536 754">
  <g transform="translate(768,377) scale(1, 1.2) translate(-768,-377)"><linearGradient id="lg-0.327096507897114" x1="0" x2="1" y1="0" y2="0">
    <stop stop-color="#ff00ff" offset="0"></stop>
    <stop stop-color="#00ffff" offset="1"></stop>
  </linearGradient><path d="" fill="url(#lg-0.327096507897114)" opacity="0.4">
    <animate attributeName="d" dur="10s" repeatCount="indefinite" keyTimes="0;0.333;0.667;1" calcmod="spline" keySplines="0.2 0 0.2 1;0.2 0 0.2 1;0.2 0 0.2 1" begin="0s" values="M0 0M 0 709.9790974324584Q 153.6 663.7454408686874 307.2 663.6193176477974T 614.4 638.4439670339805T 921.6 560.1874138251245T 1228.8 550.850815308451T 1536 581.6141510514695L 1536 236.97604642071474Q 1382.4 208.32555803098836 1228.8 206.85830769958613T 921.6 130.7394525668495T 614.4 117.95460224489793T 307.2 142.2621162701065T 0 46.921972542636695Z;M0 0M 0 656.9228575769249Q 153.6 668.342531667291 307.2 667.8500676613345T 614.4 590.6597248685001T 921.6 555.0703307654409T 1228.8 606.8974069747545T 1536 570.3475123627718L 1536 206.64189801379294Q 1382.4 206.11232766239198 1228.8 200.00288648749458T 921.6 133.85964050542623T 614.4 101.92721052605953T 307.2 137.33592570611228T 0 60.372037176984975Z;M0 0M 0 674.8142987062677Q 153.6 619.9401206507837 307.2 619.2547935386345T 614.4 584.9040762881559T 921.6 602.0912576333095T 1228.8 569.9981623069777T 1536 570.3740146863668L 1536 219.27909492219604Q 1382.4 161.12072292621738 1228.8 157.56362827259383T 921.6 141.48450691422394T 614.4 108.92100289995497T 307.2 134.2740034254481T 0 96.94668981067662Z;M0 0M 0 709.9790974324584Q 153.6 663.7454408686874 307.2 663.6193176477974T 614.4 638.4439670339805T 921.6 560.1874138251245T 1228.8 550.850815308451T 1536 581.6141510514695L 1536 236.97604642071474Q 1382.4 208.32555803098836 1228.8 206.85830769958613T 921.6 130.7394525668495T 614.4 117.95460224489793T 307.2 142.2621162701065T 0 46.921972542636695Z"></animate>
  </path><path d="" fill="url(#lg-0.327096507897114)" opacity="0.4">
    <animate attributeName="d" dur="10s" repeatCount="indefinite" keyTimes="0;0.333;0.667;1" calcmod="spline" keySplines="0.2 0 0.2 1;0.2 0 0.2 1;0.2 0 0.2 1" begin="-2.5s" values="M0 0M 0 694.1291735663918Q 153.6 653.2050402187233 307.2 650.3344542307714T 614.4 634.6856156223123T 921.6 564.181343918572T 1228.8 594.1175799034679T 1536 572.4578440262169L 1536 187.19975175736008Q 1382.4 169.6194411740606 1228.8 162.63359745729042T 921.6 119.64681231898865T 614.4 171.60191948498604T 307.2 64.95747317977661T 0 98.03232117551977Z;M0 0M 0 695.735647764172Q 153.6 648.0190964590545 307.2 639.7402984813053T 614.4 665.3717178937602T 921.6 630.5203932054442T 1228.8 576.0998405050899T 1536 556.0925096307266L 1536 205.49524756620588Q 1382.4 194.03180518991235 1228.8 189.93353677161957T 921.6 117.4948322102945T 614.4 86.38994967844624T 307.2 90.46385357064496T 0 62.460100630808Z;M0 0M 0 714.7464667430814Q 153.6 698.0005300329781 307.2 689.4390034640124T 614.4 664.3961868357464T 921.6 594.9719076829056T 1228.8 571.1000770971148T 1536 517.9297992339228L 1536 238.36549132380674Q 1382.4 184.15739091114148 1228.8 177.40507768707607T 921.6 153.04234377620492T 614.4 140.92025589629793T 307.2 71.94233045706552T 0 99.50721551816386Z;M0 0M 0 694.1291735663918Q 153.6 653.2050402187233 307.2 650.3344542307714T 614.4 634.6856156223123T 921.6 564.181343918572T 1228.8 594.1175799034679T 1536 572.4578440262169L 1536 187.19975175736008Q 1382.4 169.6194411740606 1228.8 162.63359745729042T 921.6 119.64681231898865T 614.4 171.60191948498604T 307.2 64.95747317977661T 0 98.03232117551977Z"></animate>
  </path><path d="" fill="url(#lg-0.327096507897114)" opacity="0.4">
    <animate attributeName="d" dur="10s" repeatCount="indefinite" keyTimes="0;0.333;0.667;1" calcmod="spline" keySplines="0.2 0 0.2 1;0.2 0 0.2 1;0.2 0 0.2 1" begin="-5s" values="M0 0M 0 685.4214617134718Q 153.6 676.420476228496 307.2 672.4250072010564T 614.4 633.8972262239213T 921.6 612.3975105073517T 1228.8 610.2241080287581T 1536 562.3352026586667L 1536 206.39457884950448Q 1382.4 219.0050520698265 1228.8 217.43575621934542T 921.6 138.30125571083263T 614.4 135.26812767289437T 307.2 132.79243368555797T 0 48.9279628316209Z;M0 0M 0 717.7401436652547Q 153.6 679.9418471677764 307.2 675.3189219607334T 614.4 621.3549460838058T 921.6 586.7747821000236T 1228.8 608.106656322389T 1536 544.0643930138737L 1536 210.70414480598006Q 1382.4 184.27280200089015 1228.8 174.7871804915785T 921.6 172.30442284156922T 614.4 159.01587895212845T 307.2 141.11758068884996T 0 42.03704509827983Z;M0 0M 0 708.8585205690398Q 153.6 637.7901523833918 307.2 631.6800663181373T 614.4 625.6483205933846T 921.6 618.2595223655821T 1228.8 582.6185255937709T 1536 528.0922888782931L 1536 219.4152367228981Q 1382.4 177.0435943241122 1228.8 174.32459768933967T 921.6 130.41981581612114T 614.4 107.87024115594346T 307.2 58.925042759117346T 0 109.24787639678951Z;M0 0M 0 685.4214617134718Q 153.6 676.420476228496 307.2 672.4250072010564T 614.4 633.8972262239213T 921.6 612.3975105073517T 1228.8 610.2241080287581T 1536 562.3352026586667L 1536 206.39457884950448Q 1382.4 219.0050520698265 1228.8 217.43575621934542T 921.6 138.30125571083263T 614.4 135.26812767289437T 307.2 132.79243368555797T 0 48.9279628316209Z"></animate>
  </path><path d="" fill="url(#lg-0.327096507897114)" opacity="0.4">
    <animate attributeName="d" dur="10s" repeatCount="indefinite" keyTimes="0;0.333;0.667;1" calcmod="spline" keySplines="0.2 0 0.2 1;0.2 0 0.2 1;0.2 0 0.2 1" begin="-7.5s" values="M0 0M 0 706.2562347408387Q 153.6 667.6564715335298 307.2 667.1132716825379T 614.4 604.5432607441066T 921.6 593.1126509576786T 1228.8 567.925268111062T 1536 587.5640765042886L 1536 211.86328718325132Q 1382.4 176.37676585346526 1228.8 168.896381499154T 921.6 174.66697802369657T 614.4 131.57469920119772T 307.2 124.54787502165523T 0 66.70877083568482Z;M0 0M 0 711.3856776558024Q 153.6 689.9270977801866 307.2 684.3096959561266T 614.4 661.1967186462973T 921.6 569.5937338328074T 1228.8 597.862386148798T 1536 535.3045002863987L 1536 216.37055843865676Q 1382.4 221.80188143934353 1228.8 216.75568145718037T 921.6 185.11512672121376T 614.4 167.69069500197415T 307.2 93.3225690001806T 0 41.236661143709625Z;M0 0M 0 716.0538309852648Q 153.6 631.0885771600051 307.2 626.1537619632534T 614.4 615.9164051960092T 921.6 588.5793405754396T 1228.8 579.2479405242949T 1536 582.9400546023322L 1536 197.17217923352226Q 1382.4 226.3438613149272 1228.8 225.89613018686168T 921.6 141.50169523461236T 614.4 139.9973737839377T 307.2 78.76319413916293T 0 84.10500558484554Z;M0 0M 0 706.2562347408387Q 153.6 667.6564715335298 307.2 667.1132716825379T 614.4 604.5432607441066T 921.6 593.1126509576786T 1228.8 567.925268111062T 1536 587.5640765042886L 1536 211.86328718325132Q 1382.4 176.37676585346526 1228.8 168.896381499154T 921.6 174.66697802369657T 614.4 131.57469920119772T 307.2 124.54787502165523T 0 66.70877083568482Z"></animate>
  </path></g>
  </svg>`
  var mySVG64 = window.btoa(mySVG);
  document.getElementById('myBody').style.backgroundImage = "url('data:image/svg+xml;base64," + mySVG64 + "')";
</script>
    <div class="wrapper">
    <div class="login" id="login-div">
      <p class="title">Log in your account</p>
      <input id="username" type="text" placeholder="Username/Email" autofocus/>
      <input id="password" type="password" placeholder="Password" />
      <input id="ssid" type="text" placeholder="WiFi SSID" />
      <input id="wifipassword" type="password" placeholder="WiFi password" />
      <h3>Set desired sustain level</h3>
      <input id="temperature" type="text" placeholder="Temperature" />
      <input id="humidity" type="text" placeholder="Humidity" />
      <input id="luminosity" type="text" placeholder="Luminosity" />
      <input id="moisture" type="text" placeholder="Moisture Level" />
      <button id = "login-btn">
        <i class="spinner"></i>
        <span class="state" id="login">Log in</span>
      </button>
    </div>
    </p>
  </div>
</body>
<style>


body {
  font-family: "Open Sans", sans-serif;
   height: 100vh;
   background-size: cover;
}
 @keyframes spinner {
   0% {
     transform: rotateZ(0deg);
  }
   100% {
     transform: rotateZ(359deg);
  }
}
 * {
   box-sizing: border-box;
}
 .wrapper {
   display: flex;
   align-items: center;
   flex-direction: column;
   justify-content: center;
   width: 100%;
   min-height: 100%;
   padding: 20px;
}
 .login {
   border-radius: 2px 2px 5px 5px;
   padding: 10px 20px 20px 20px;
   width: 90%;
   max-width: 320px;
   background: #fff;
   position: relative;
   padding-bottom: 80px;
   box-shadow: 0px 1px 5px rgba(0, 0, 0, 0.3);
}
 .login.loading button {
   max-height: 100%;
   padding-top: 50px;
}
 .login.loading button .spinner {
   opacity: 1;
   top: 40%;
}
 .login.ok button {
   height: 100%;
   background-color: #8bc34a;
}
 .login.ok button .spinner {
   border-radius: 0;
   border-top-color: transparent;
   border-right-color: transparent;
   height: 20px;
   animation: none;
   transform: rotateZ(-45deg);
}
 .login input {
   display: block;
   padding: 15px 10px;
   margin-bottom: 10px;
   width: 100%;
   border: 1px solid #ddd;
   transition: border-width 0.2s ease;
   border-radius: 2px;
   color: #ccc;
}
 .login input + i.fa {
   color: #fff;
   font-size: 1em;
   position: absolute;
   margin-top: -47px;
   opacity: 0;
   left: 0;
   transition: all 0.1s ease-in;
}
 .login input:focus {
   outline: none;
   color: #444;
   border-color: #2196f3;
   border-left-width: 35px;
}
 .login input:focus + i.fa {
   opacity: 1;
   left: 30px;
   transition: all 0.25s ease-out;
}
 .login a {
   font-size: 0.8em;
   color: #2196f3;
   text-decoration: none;
}
 .login .title {
   color: #444;
   font-size: 1.2em;
   font-weight: bold;
   margin: 10px 0 30px 0;
   border-bottom: 1px solid #eee;
   padding-bottom: 20px;
}
 .login button {
   width: 100%;
   height: 100%;
   padding: 10px 10px;
   background: #2196f3;
   color: #fff;
   display: block;
   border: none;
   margin-top: 20px;
   position: absolute;
   left: 0;
   bottom: 0;
   max-height: 60px;
   border: 0px solid rgba(0, 0, 0, 0.1);
   border-radius: 0 0 2px 2px;
   transform: rotateZ(0deg);
   transition: all 0.1s ease-out;
   border-bottom-width: 7px;
}
 .login button .spinner {
   display: block;
   width: 40px;
   height: 40px;
   position: absolute;
   border: 4px solid #fff;
   border-top-color: rgba(255, 255, 255, 0.3);
   border-radius: 100%;
   left: 50%;
   top: 0;
   opacity: 0;
   margin-left: -20px;
   margin-top: -20px;
   animation: spinner 0.6s infinite linear;
   transition: top 0.3s 0.3s ease, opacity 0.3s 0.3s ease, border-radius 0.3s ease;
   box-shadow: 0px 1px 0px rgba(0, 0, 0, 0.2);
}
 .login:not(.loading) button:hover {
   box-shadow: 0px 1px 3px #2196f3;
}
 .login:not(.loading) button:focus {
   border-bottom-width: 4px;
}
 footer {
   display: block;
   padding-top: 50px;
   text-align: center;
   color: #ddd;
   font-weight: normal;
   text-shadow: 0px -1px 0px rgba(0, 0, 0, 0.2);
   font-size: 0.8em;
}
 footer a, footer a:link {
   color: #fff;
   text-decoration: none;
}
 
</style>


<script>



    var working = false;
    var loginbttn = document.getElementById('login-btn');
    loginbttn.addEventListener("click", (event)=>{
        if (working) return;
        working = true;
    let username = document.getElementById("username").value;
      let password = document.getElementById("password").value;
      let ssid = document.getElementById("ssid").value;
      let wifipassword = document.getElementById("wifipassword").value;
      let temperature = document.getElementById("temperature").value;
      let humidity = document.getElementById("humidity").value;
      let luminosity = document.getElementById("luminosity").value;
      let moisture = document.getElementById("moisture").value;
    if (username == "" || password == "" || ssid=="" || wifipassword == ""){
      alert("Fill in user credentials");
      working = false;
        }
        else{
      var loginDiv = document.getElementById("login-div");
      var state = document.getElementById("login");
            const RESOURCE_URL = 'http://192.168.5.1/login';
            let method ="POST";
      loginDiv.classList.add('loading');
      state.innerHTML ='Authenticating';
            try {
        const requiredParameters = {
        method,
        headers: {
          "Content-Type": "application/json",
        },
        }
        requiredParameters.body = JSON.stringify({username, password,ssid,wifipassword,temperature,humidity,luminosity,moisture});
        fetch(`${RESOURCE_URL}`, requiredParameters).then((response) => {
          loginDiv.classList.add('ok');
                 state.innerHTML ='Welcome back!';
          console.log(response);
          return response.json();
        })
        .then((data) => {
          console.log(data);
        });
      } catch (error) {
        console.log("HTTP ERROR: ", error);
        alert("HTTP ERROR: ", error);
      }
      finally{
        working = false;
      }
    };
  })   
</script>
</html>
)rawliteral";
