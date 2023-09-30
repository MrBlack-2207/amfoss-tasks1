const API_key = "2a86d9142bbfd6ea499a86719213f723";

window.onload = function () {
    document.getElementById("getWeather").addEventListener("click", function() {
        const location = document.getElementById("locationInput").value;
        getWeather(location);
    });
}

function getWeather(location) {
    fetch(`https://api.openweathermap.org/data/2.5/weather?q=${location}&units=metric&appid=${API_key}`)
        .then((data) => data.json())
        .then((jsonData) => {
            document.getElementById("text_location").innerHTML = jsonData.name;
            document.getElementById("text_location_country").innerHTML = jsonData.sys.country;
            document.getElementById("text_temp").innerHTML = Math.round(jsonData.main.temp);
            document.getElementById("text_feelslike").innerHTML = "&nbsp;" + Math.round(jsonData.main.feels_like);
            document.getElementById("text_desc").innerHTML = jsonData.weather[0].description;

            const iconURL = `https://openweathermap.org/img/wn/${jsonData.weather[0].icon}.png`;
            document.getElementById("icon").src = iconURL;

            setWeatherBackground(jsonData.weather[0].description);  
        })
        .catch(error => console.error('Error:', error));
}

function setWeatherBackground(weatherDescription) {

    console.log("setWeatherBackground called");
    const body = document.getElementById("body");
    if (weatherDescription.includes("rain")) {
        body.style.backgroundImage = "url('rain.jpg')";
    } else if (weatherDescription.includes("clear")) {
        body.style.backgroundImage = "url('clear.jpg')";
    } else if (weatherDescription.includes("cloud")) {
        body.style.backgroundImage = "url('cloud.jpg')";
    } else if (weatherDescription.includes("thunder")) {
        body.style.backgroundImage = "url('thunder.jpg')";
    } else {
        body.style.backgroundImage = "url('default.jpg')";
    }
}

