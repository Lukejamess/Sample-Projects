"use strict";

$(document).ready( () => {
	
	//move focus to first box
	$("#arrival_date").focus();
	
	$("#reservation_form").submit( event => {
		
		// set validation boolean
		let isValid = true;
		
		//validate arrival date
		const arrival = $("#arrival_date").val().trim();
		if (arrival == "") {
			$("#arrival_date").next().text("This field is required.");
			isValid = false;
		}else {
			$("#arrival_date").next().text("");
		}
		$("#arrival_date").val(arrival);
	
		//validate number of nights making sure it is a number
		const nights = $("#nights").val().trim();
		if (nights == "") {
			$("#nights").next().text("This field is required.");
			isValid = false;
		}else if ((isNaN(nights))) {
			$("#nights").next().text("Must be a number.");
			isValid = false;
		}else {
			$("#nights").next().text("");
		}
		$("#nights").val(nights);
		
		//validate name
		const name = $("#name").val().trim();
		if (name == "") {
			$("#name").next().text("This field is required.");
			isValid = false;
		}else {
			$("#name").next().text("");
		}
		$("#name").val(arrival);
		
		//validate email against email pattern criteria
		const emailPattern = /\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}\b/;
		const email = $("#email").val().trim();	
		if (email == "") {
			$("#email").next().text("This field is required.");
			isValid = false;
		} else if ( !emailPattern.test(email) ){
			$("#email").next().text("Must be a valid email address.");
			isValid = false;
		}else {
			$("#email").next().text("");
		}
		$("#email").val(email);
		
		//validate phone number against phone number criteria
		const phonePattern= /^\(?([0-9]{3})\)?[-. ]?([0-9]{3})[-. ]?([0-9]{4})$/;
		const phone = $("#phone").val().trim();	
		if (phone == "") {
			$("#phone").next().text("This field is required.");
			isValid = false;
		} else if ( !phonePattern.test(phone) ){
			$("#phone").next().text("Must be a valid phone number.");
			isValid = false;
		}else {
			$("#phone").next().text("");
		}
		$("#phone").val(phone);
		
		//don't send form if data is not valid
		if (isValid == false) {
			event.preventDefault();
		}
		
	});	// end validation function	
		
}); // end ready