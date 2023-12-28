function geoplugin_request() { return '152.168.48.76';} 
function geoplugin_status() { return '200';} 
function geoplugin_credit() { return 'Some of the returned data includes GeoLite data created by MaxMind, available from <a href=\'http://www.maxmind.com\'>http://www.maxmind.com</a>.';} 
function geoplugin_delay() { return '1ms';} 
function geoplugin_city() { return 'Beccar';} 
function geoplugin_region() { return 'Buenos Aires';} 
function geoplugin_regionCode() { return 'B';} 
function geoplugin_regionName() { return 'Buenos Aires';} 
function geoplugin_areaCode() { return '';} 
function geoplugin_dmaCode() { return '';} 
function geoplugin_countryCode() { return 'AR';} 
function geoplugin_countryName() { return 'Argentina';} 
function geoplugin_inEU() { return 0;} 
function geoplugin_euVATrate() { return ;} 
function geoplugin_continentCode() { return 'SA';} 
function geoplugin_latitude() { return '-34.4698';} 
function geoplugin_longitude() { return '-58.5377';} 
function geoplugin_locationAccuracyRadius() { return '10';} 
function geoplugin_timezone() { return 'America/Argentina/Buenos_Aires';} 
function geoplugin_currencyCode() { return 'ARS';} 
function geoplugin_currencySymbol() { return '&#36;';} 
function geoplugin_currencySymbol_UTF8() { return '$';} 
function geoplugin_currencyConverter(amt, symbol) { 
	if (!amt) { return false; } 
	var converted = amt * 83.3584; 
	if (converted <0) { return false; } 
	if (symbol === false) { return Math.round(converted * 100)/100; } 
	else { return '&#36;'+(Math.round(converted * 100)/100);} 
	return false; 
} 
