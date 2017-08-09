void blue_send(){

    // improve this to get rid of buffer by printing each char one by one
    snprintf_P(Buffer, 60, PSTR("%d:%d:%d %d/%d/%d,%c,%d.%d,%d.%d,%d,%d,%d,%d\n"), hour, minute, second, day, month, year, PIR, (int)temperature, (int)(temperature * 100) % 100, (int)humidity, (int)(humidity * 100) % 100, CO2, PM1, PM25, PM10);
    Serial.print(Buffer);
}