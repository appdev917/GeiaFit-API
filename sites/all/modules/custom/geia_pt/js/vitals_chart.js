/**
* @file
* chart for vitals/Characteristics.
*/
(function ($) { 
    var element = $('#vitals-chart');
    if (element.length === 0) {
        return;
    }

    var options = {
        series: {
            lines: {
                show: true,
                lineWidth: 2, 
                fill: false
            },
            points: {
                show: true, 
                lineWidth: 3,
                fill: true,
                fillColor: "#fafafa"
            },
            shadowSize: 0
        },
        grid: {
            hoverable: true, 
            clickable: true,
            borderWidth: 0,
            tickColor: "#E4E4E4",
        },
        colors: ["#d9d9d9", "#5399D6"],
        yaxis: {
            font: { color: "#555" },
        },
        xaxis: {
            font: { color: "#555" },
            tickColor: "#fafafa",
        },
        legend: {
            labelBoxBorderColor: "transparent",
            backgroundColor: "transparent"
        },
        tooltip: true,
        tooltipOpts: {
            content: '%s: %y'
        }
    };  

    var periodSelector = 'input[name="period"]';
    var parameterSelector = 'input[name="parameter"]';
    var vital_params = Drupal.settings.vital_params;
    var period = $(periodSelector).val();
    var parameter = $(parameterSelector).val();

    function plotVitals() {
        var data = vital_params[period];
        options.xaxis.ticks = data.ticks;
        $.plot(element, [data.series[parameter].data], options);
    }

    $(periodSelector).change(function() {
        period = $(this).val();
        plotVitals();
    });
    
    $(parameterSelector).change(function() {
        parameter = $(this).val();
        plotVitals();
    });

    plotVitals(); 
})(jQuery);
