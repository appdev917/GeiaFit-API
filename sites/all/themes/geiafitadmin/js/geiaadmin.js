(function ($) { 
$(document).ready(function(){

	//Stack menu when collapsed
	$('#pt-patient-navbar').on('show.bs.collapse', function() {
    	$('.nav-pills').addClass('nav-stacked');
	});

	//Unstack menu when not collapsed
	$('#pt-patient-navbar').on('hide.bs.collapse', function() {
    	$('.nav-pills').removeClass('nav-stacked');
	});

}); // end ready function

})(jQuery);