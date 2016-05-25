#include "Serial_LCD_SparkFun/Serial_LCD_SparkFun.h"

/*
Use the 3_20x4_tester.html to exercise the display with this script.

Limitations : sending strings that wrap lines can cause strange wrapping
            : there is little to no error checking / reporting
*/


// Create two functions, one for writing on each row
int lcdMsgRow(String command);
int lcdMsgCol(String command);
int lcdMsgTxt(String command);
int row = 1;
int col = 1;

// Initialize the LCD library
Serial_LCD_SparkFun lcd = Serial_LCD_SparkFun();

void setup() {
    Serial.begin( 9600 );
 // Registering our two cloud functions
 Spark.function("lcdRow", lcdMsgRow);
 Spark.function("lcdCol", lcdMsgCol);
 Spark.function("lcdTxt", lcdMsgTxt);
 
 // Start with a blank slate
 lcd.setType( 6 );
 lcd.clear();
 lcd.setBrightness( 30 );
 Serial1.print("Waiting");
}

// Don't need to do anything in the loop
void loop() {}

// Set the row
int lcdMsgRow(String command){
    Serial.print( "lcdMsgRow : '");
    Serial.print( command );
    Serial.println( "'" );
    
    row = command.toInt();
    
    // Return 1 for giggles
    return 1;
}

//Set the column
int lcdMsgCol(String command){
    
    Serial.print( "lcdMsgCol : '");
    Serial.print( command );
    Serial.println( "'" );
    
    col = command.toInt();
    
    return 1;
}

//Set the text
int lcdMsgTxt(String command){
    
    Serial.print( "lcdMsgTxt : '");
    Serial.print( command );
    Serial.println( "'" );
    
    lcd.clear();
    lcd.setCursor( row, col );

    Serial1.print(command);
    return 1;
}

