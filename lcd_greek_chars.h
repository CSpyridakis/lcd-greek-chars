// ---------------------------------------------------------------------------------
//   Use greek characters on 1602/2004 LCD screen with arduino or other related MCUs
//
//   Author  : Spyridakis Christos
//   Email   : spyridakischristos@gmail.com
//   Created Date : 12/4/2020
//   Last Updated : 13/4/2020
//  
//   Description: Δυστυχώς λόγο του περιορισμού της μνήμης του HD44780 που βρίσκεται
//                συνήθως σε αυτές τις οθόνες μπορούν να προσθέσουμε μόνο 8 επιπλέον
//                χαρακτήρες, για να γίνει εφικτή η εγγραφή σε ελληνικά. Για αυτόν τον 
//                λόγο μετατρέπεται κάθε ελληνικός χαρακτήρας σε κεφαλαία.
//
//   See: 
//      - [1] https://www.sparkfun.com/datasheets/LCD/HD44780.pdf
//      - [2] https://forum.arduino.cc/index.php?topic=48508.0
//      - [3] https://maxpromer.github.io/LCD-Character-Creator/
//
// ---------------------------------------------------------------------------------

#ifndef LCD_GREEK_CHARS_H
#define LCD_GREEK_CHARS_H

#ifndef I2C
    #include <LiquidCrystal.h>
#else
    #include <LiquidCrystal_I2C.h>    
#endif

// 2004 LCD
#define ROWS 4
#define COLUMNS 20

#ifndef FALSE
    #define FALSE 0
#endif

#ifndef TRUE
    #define TRUE 1
#endif

#ifndef DEBUG
    #define DEBUG FALSE
#endif

byte Gama[8]  = {B11111, B10000, B10000, B10000, B10000, B10000, B10000};
byte Delta[8] = {B00100, B01010, B01010, B10001, B10001, B10001, B11111};
byte Thita[8] = {B01110, B10001, B10001, B11111, B10001, B10001, B01110};
byte Lamda[8] = {B00100, B01010, B01010, B10001, B10001, B10001, B10001};
byte Ksi[8]   = {B11111, B00000, B00000, B01110, B00000, B00000, B11111};
byte Pi[8]    = {B11111, B10001, B10001, B10001, B10001, B10001, B10001};
byte Fi[8]    = {B00100, B01110, B10101, B10101, B10101, B01110, B00100};
byte Psi[8]   = {B10001, B10101, B10101, B10101, B01110, B00100, B00100};
byte Sigma[8] = {B11111, B01000, B00100, B00010, B00100, B01000, B11111};
byte Omega[8] = {B01110, B10001, B10001, B10001, B01010, B01010, B11011};

#define GAMA 0
#define DELTA 1
#define THITA 2
#define LAMDA 3
#define KSI 4
#define PI 5
#define FI 6
#define PSI 7
#define SIGMA 246
#define OMEGA 244


/**
 *  \brief  Create the required characters. Some Greek characters (e.g. A, K, P, O) could 
 *          be borrowed from English, others like Φ, Ψ, Σ, etc. need to design from scratch.
 *  
 *  \param lcd  LCD's Object that you created on your sketch initialization
 * 
 *  \see https://maxpromer.github.io/LCD-Character-Creator/
 */
void createGreekChars(LiquidCrystal_I2C lcd){
    lcd.clear();
    lcd.createChar(GAMA, Gama);
    lcd.createChar(DELTA, Delta);
    lcd.createChar(THITA, Thita);
    lcd.createChar(LAMDA, Lamda);
    lcd.createChar(KSI, Ksi);
    lcd.createChar(PI, Pi);
    lcd.createChar(FI, Fi);
    lcd.createChar(PSI, Psi);
}


/**
 *  \brief  Display text on LCD
 * 
 *  \param lcd     LCD's Object that you created on your sketch initialization
 *  \param text    Text that you want to display (it could contain greek/english chars, symbols or numbers)
 *  \param row     The row that you want to display text
 *  \param column  The column that you want to display text
 * 
 *  \see https://www.sparkfun.com/datasheets/LCD/HD44780.pdf
 */
void ektypwse(LiquidCrystal_I2C lcd, unsigned char text[], unsigned int row, unsigned int column){
    
    unsigned int i=0, r=row, c=column;
    lcd.setCursor(c, r);
    while(text[i]!='\0'){
        if (c >=(unsigned int)COLUMNS) {r++; c=0; lcd.setCursor(c, r);}
        if (r >=(unsigned int)ROWS){break;}
        switch (text[i]){
            case 206: case 127: case 207: break;                // Weird Characters
            case 145: case 177: case 172:                       lcd.write('A');   c++; break;           
            case 146: case 178:                                 lcd.write('B');   c++; break;               
            case 147: case 179:                                 lcd.write(GAMA);  c++; break;
            case 148: case 180:                                 lcd.write(DELTA); c++; break;             
            case 149: case 181: case 173:                       lcd.write('E');   c++; break;                  
            case 150: case 182:                                 lcd.write('Z');   c++; break;               
            case 151: case 183: case 174:                       lcd.write('H');   c++; break; 
            case 152: case 184:                                 lcd.write(THITA); c++; break;             
            case 153: case 185: case 175: case 144: case 138:   lcd.write('I');   c++; break;             
            case 154: case 186:                                 lcd.write('K');   c++; break;       
            case 155: case 187:                                 lcd.write(LAMDA); c++; break;              
            case 156: case 188:                                 lcd.write('M');   c++; break;               
            case 157: case 189:                                 lcd.write('N');   c++; break;               
            case 158: case 190:                                 lcd.write(KSI);   c++; break;   
            case 159: case 191: case 140:                       lcd.write('O');   c++; break;                     
            case 160: case 128:                                 lcd.write(PI);    c++; break; 
            case 161: case 129:                                 lcd.write('P');   c++; break;  
            case 163: case 131: case 130:                       lcd.write(SIGMA); c++; break; 
            case 164: case 132:                                 lcd.write('T');   c++; break; 
            case 165: case 133: case 141: case 139: case 176:   lcd.write('Y');   c++; break;                  
            case 166: case 134:                                 lcd.write(FI);    c++; break; 
            case 167: case 135:                                 lcd.write('X');   c++; break;  
            case 168: case 136:                                 lcd.write(PSI);   c++; break; 
            case 169: case 137: case 142:                       lcd.write(OMEGA); c++; break; 
            default: lcd.write(text[i]); if(DEBUG) Serial.println(int(text[i]));  c++; break;              
        }
        i++; 
        delay(1);
    }
}

#endif //LCD_GREEK_CHARS_H
