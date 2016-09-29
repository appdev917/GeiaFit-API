(function ($) {
    var options = {
        stack: true,
        bars: {
            show: true,
            barWidth: 0.6,
            align: "center"
        },
        grid: {
            hoverable: true,
            clickable: true,
            borderWidth: 0,
            tickColor: "#E4E4E4"
        },
        colors: ["#4382b8", "#5db3ff"],
        yaxis: {
            font: { color: "#555" }
        },
        xaxis: {
            font: { color: "#555" },
            tickColor: "#fafafa",
            autoscaleMargin: 0.2
        },
        legend: {
            labelBoxBorderColor: "transparent",
            backgroundColor: "transparent"
        },
        tooltip: true,
        tooltipOpts: {
            content: '%s: %y'
        }
    }

    var days7ParamSelector = 'input[name="days7_param"]';
    var days30ParamSelector = 'input[name="days30_param"]';
    var activities = Drupal.settings.activities;
    var days7Param = $(days7ParamSelector).val();
    var days30Param = $(days30ParamSelector).val();

    function plotDays7() {
        options.xaxis.ticks = activities.days7.ticks;
        $.plot($('#activities-days7'), activities.days7.data[days7Param], options);
    }

    function plotDays30() {
        options.xaxis.ticks = activities.days30.ticks;
        $.plot($('#activities-days30'), activities.days30.data[days30Param], options);
    }

    $(days7ParamSelector).change(function() {
        days7Param = $(this).val();
        plotDays7();
    });

    $(days30ParamSelector).change(function() {
        days30Param = $(this).val();
        plotDays30();
    });

    plotDays7();
    plotDays30();
})(jQuery);
