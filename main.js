var sensorDataArr = [];

const getAllData = async () => {
    const rawResponse = fetch("http://localhost:8080/sensors")
    .then(response => response.json())
    .then(commits => sensorDataArr = commits);
    return sensorDataArr;
}

var loadButton = document.getElementById("loadButton");
var loadedData = document.getElementById("loadedData");
var table = document.getElementById("table");
var tableSign = document.getElementById("tableSign");
loadButton.addEventListener("click",(event)=>{
    getAllData();
    sensorDataArr.sort((a,b) => new Date(b.data.time) - new Date(a.data.time));
    table.style.visibility='visible';
    tableSign.style.visibility='visible';
    for(var i =0; i<table.rows.length -1; i++){
            table.rows[i+1].cells[1].innerHTML = sensorDataArr[i].data.temperature;
            table.rows[i+1].cells[2].innerHTML = sensorDataArr[i].data.humidity;
            table.rows[i+1].cells[3].innerHTML = sensorDataArr[i].data.luminosity;
            table.rows[i+1].cells[4].innerHTML = sensorDataArr[i].data.soilMoisture;
            table.rows[i+1].cells[5].innerHTML = sensorDataArr[i].data.time;
    }
});
