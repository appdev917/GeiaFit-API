/**
* @file
* slider js integration.
*/
(function ($) { 
	
	var steps_low = Drupal.settings.geia_pt.steps_low;
	var steps_high = Drupal.settings.geia_pt.steps_high;
	
	var hr_low = Drupal.settings.geia_pt.hr_low;
	var hr_high = Drupal.settings.geia_pt.hr_high;
	
	
	$('.steps_slider').rangeSlider({
	    bounds: {min: 5, max: 300},
		defaultValues:{min: steps_low, max: steps_high}
	});
	
	$(".steps_slider").bind("valuesChanged", function(e, data){
	  console.log("Values just changed. min: " + Math.round(data.values.min) + " max: " + data.values.max);
	  $("#steps_low").val(Math.round(data.values.min));
	  $("#steps_high").val(Math.round(data.values.max));
	});
	
	
	$('.hr_slider').rangeSlider({
	    bounds: {min: 40, max: 230},
		defaultValues:{min: hr_low, max: hr_high}
	});
	
	$(".hr_slider").bind("valuesChanged", function(e, data){
	  console.log("HR Values just changed. min: " + data.values.min + " max: " + data.values.max);
	  $("#hr_low").val(Math.round(data.values.min));
	  $("#hr_high").val(Math.round(data.values.max));
	});
	
})(jQuery);


			
