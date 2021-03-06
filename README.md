# lcd-greek-chars ![license](https://img.shields.io/github/license/CSpyridakis/lcd-greek-chars?style=plastic) ![Size](https://img.shields.io/github/repo-size/CSpyridakis/lcd-greek-chars.svg?style=plastic)

A header file to use Greek Characters on 2004/1602 LCD Screen (with or without I2C) from arduino or other related MCUs.

## Χρήση
Για να μπορέσετε να εμφανίσετε ελληνικούς χαρακτήρες στην οθόνη σας, αρκεί να κάνετε
include το header file lcd-greek-chars.h, να χρησιμοποιήσετε κατά το setup την μέθοδο 
createGreekChars() και κάθε φορά που θέλετε να εμφανίσετε κείμενο στην LCD αντί της lcd.print να χρησιμοποιήσετε την ektypwse(). 

## Example
Μπορείτε να βρείτε παράδειγμα χρήσης της βιβλιοθήκης στον ομότιτλο [φάκελο](./example).

![Example](./doc/example.jpg)

![Example2](./doc/exampl2.jpg)

## Note:
Δυστυχώς λόγω του περιορισμού της μνήμης του [HD44780](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf) 
που βρίσκεται συνήθως σε αυτές τις οθόνες μπορούν να προστεθούν μόνο 8 επιπλέον
χαρακτήρες, οι οποίοι είναι και αναγκαίοι για να γίνει εφικτή η 
εγγραφή σε ελληνικά. Για αυτόν τον λόγο μετατρέπεται κάθε ελληνικός χαρακτήρας σε κεφαλαία ωστέ να μπορεί να γραφτεί 
οποιαδήποτε ελληνική λέξη.
