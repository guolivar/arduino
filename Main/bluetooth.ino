void blue_send(){

    // improve this to get rid of buffer by printing each char one by one
    snprintf_P(Buffer, 62, PSTR( BOX_ID "_%d-%d-%d-%d-%d-%d_%d_%d_%d_%d.%d_%d.%d_%d_%c"), year, month, day, hour, minute, second, PM1, PM25, PM10,(int)temperature, (int)(temperature * 100) % 100, (int)humidity, (int)(humidity * 100) % 100, CO2, PIR);
    Serial.println(Buffer);
}