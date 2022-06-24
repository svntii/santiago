#!/bin/sh

# weather.sh
# fetch the weather information for any specified zip code and extract the temperature and forecast

# GLOBALS

URL="https://forecast.weather.gov/zipcity.php"
ZIPCODE=46556
FORECAST=0
CELSIUS=0

# FUNCTIONS

usage() {
	cat 1>&2 <<EOF
Usage: $(basename $0) [zipcode]

-c    Use Celsius degrees instead of Fahrenheit for temperature
-f    Display forecast text

If zipcode is not provided, then it defaults to $ZIPCODE.
EOF
    exit $1
}

weather_information() {
		    # Fetch weather information from URL based on ZIPCODE
			curl -sL https://forecast.weather.gov/zipcity.php\?inputstring\=$ZIPCODE | grep "myforecast-current" | cut -d ">" -f 2 | cut -d "<" -f 1 
}

temperature() {
			    # Extract temperature information from weather source
			TEMP="F"
			if [ $CELSIUS -eq 1 ]; then
				TEMP="C"
			fi
			weather_information | grep -E "$TEMP$" | sed "s_&deg;[CF]_ _g"
}

forecast() {
					    # Extract forecast information from weather source
			weather_information | grep -E "([^CF]$)" | sed "s|^ ||g"
}



# PARSING

while [ $# -gt 0 ]; do
		case $1 in
				-h) usage 0;;
				-f) FORECAST=1;;
				-c) CELSIUS=1;;
				-*) usage 1;;
				 *) ZIPCODE=$1
		esac	
		shift
done

if [ -z $ZIPCODE ];then
		ZIPCODE=46556
fi

# Display Information
if [ $FORECAST -eq 1 ]; then
	echo "Forecast:    $(forecast)"
fi
echo "Temperature: $(temperature)degrees"

