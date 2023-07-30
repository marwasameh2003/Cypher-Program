// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: All Ciphers Program.cpp
// Program Description: This program encrypt and decrypt the message the user input in the way the user choosed.
// Last Modification Date: 25/3/2022
// Author 1 and ID and Group: Rawan Hesham, 20211040, Group A
// Author 1 and ID and Group: Marwa Sameh, 20210514, Group A.
// Author 1 and ID and Group: Mai Mohamed, 20211098, Group A.
// Teaching Assistant: S2 /
// Purpose: To encrypt and decrypt any message in many ways.

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cctype>
#include <cmath>
#include<iomanip>
using namespace std;

// all function in the program.
void AffineCipher();
void CaesarCipher();
void VignereCipher();
void BaconianCipher();
void MorseCode();
void PolybiusSquareCipher();
void AtbashCipher();
void XORCipher();

int main()
{
    int choice;
    // greet the user :)
    cout << "Ahlan ya user ya habibi.\nWhat do you like to do today?" << endl;
    cout << endl;
    cout << "1- Affine Cipher.\n2- Caesar Cipher.\n3- Atbash Cipher.\n4- Vignere Cipher.\n5- Baconian Cipher.\n6- Simple Substitution Cipher.\n7- Polybius Square Cipher.\n8- Morse Code.\n9- XOR Cipher.\n10- Rail-fence Cipher.\n11- End" << endl;
    cout << endl;
    // let the user choose the way of encryption and decryption.
    cout << "Choose a number (1 to 10): ";
    cin >> choice;
    // the list for all ciphers will appear to user until the user choose 11 which indicated to end the program.
    while(choice != 11){
        switch(choice){
        case 1 : AffineCipher();break;
        case 2 : CaesarCipher();break;
        case 3 : AtbashCipher();break;
        case 4 : VignereCipher();break;
        case 5 : BaconianCipher();break;
        case 7 : PolybiusSquareCipher();break;
        case 8 : MorseCode();break;
        case 9 : XORCipher();break;

    }
        cout << endl;
        cout << "Ahlan ya user ya habibi.\nWhat do you like to do today?" << endl;
        cout << endl;
        cout << "1- Affine Cipher.\n2- Caesar Cipher.\n3- Atbash Cipher.\n4- Vignere Cipher.\n5- Baconian Cipher.\n6- Simple Substitution Cipher.\n7- Polybius Square Cipher.\n8- Morse Code.\n9- XOR Cipher.\n10- Rail-fence Cipher.\n11- End" << endl;
        cout << endl;
        cout << "Choose a number (1 to 10): ";
        cin >> choice;
    }
    system("pause>0");
    return 0;
}

// function for Affine Cipher.
void AffineCipher(){
    int choice;
    cout << endl;
    // let the user to choose cipher or decipher.
    cout << "What do you like to do?\n1- Cipher a message\n2- Decipher a message" << endl;
    cout << endl;
    cout << "Choose a number(1 or 2): ";
    cin >> choice;

    // if the user choose 1, the encryption will be implemented.
    if(choice == 1)
    {
        // a, b, c are arbitrary positive integers that satisfy the condition (a * c) mod 26 = 1
        int a, b, c;
        string encMessage = " ";
        cout << "a, b, c: ";
        cin >> a >> b >> c;
        // make sure that the condition is approved. if not we will take from the user another inputs until enter a valid input.
        while((a * c) % 26 != 1){
            cout << "invalid, enter another a, b, c: ";
            cin >> a >> b >> c;
        }

        // take the message from the user.
        cout << "enter the message you want to encrypt: ";
        string message;
        cin.ignore();
        getline(cin, message);
        // for loop to encrypt each character and assign them to the new variable(encMessage)
        for (int i = 0; i < message.length(); i++) {
            // make sure that the space is not encrypted.
            if(message[i] == ' ')
                encMessage += message[i];
            else
                // The equation for encrypting each character --> (a x + b) mod 26 where x is the letter to cipher.
                encMessage = encMessage + (char) (((((a * (toupper(message[i])) - 65)) + b) % 26) + 65);
        }
        // show the user the encrypted message.
        cout << "Encrypted message is: " << encMessage << endl;
        cout << endl;

    // if the user choose 2, the decryption will be implemented.
    }else if(choice == 2)
    {
        // a, b, c are arbitrary positive integers that satisfy the condition (a * c) mod 26 = 1
        int a, b, c;
        string decMessage = " ";
        cout << "a, b, c: ";
        cin >> a >> b >> c;
        // make sure that the condition is approved. if not we will take from the user another inputs until enter a valid input.
        while((a * c) % 26 != 1){
            cout << "invalid, enter another a, b, c: ";
            cin >> a >> b >> c;
        }

        // take the message from the user to decrypt it.
        cout << "enter the message you want to decrypt: ";
        string message;
        cin.ignore();
        getline(cin, message);

        // for loop to decrypt each character.
        for(int i = 0; i < message.length(); i++){
            if(message[i] == ' ')
                // make sure that the space is not decrypted.
                decMessage += message[i];
            else
                // The equation for decrypting each character --> c(y - b) mod 26 where y is the letter to decipher.
                decMessage += (char) ((((c * (toupper(message[i])+ 65 - b)) % 26)) + 65);
        }
        // show the user the decrypted message.
        cout << "Decrypted message is: " << decMessage << endl;
        cout << endl;
        }
}

// function for Caesar Cipher
void CaesarCipher(){
    int choice;
    cout << endl;
    // let the user to choose cipher or decipher.
    cout << "What do you like to do?\n1- Cipher a message\n2- Decipher a message" << endl;
    cout << endl;
    cout << "Choose a number(1 or 2): ";
    cin >> choice;

    // if the user choose 1, the encryption will be implemented.
    if (choice == 1)
    {
        string message;
        string encMessage = " ";
        // take from the user the message to encrypt.
        cout << "Enter the message you want to encrypt: ";
        cin.ignore();
        getline(cin, message);
        int shifts;
        // take the number of shifts the user want.
        cout << "Enter the number of shifts: ";
        cin >> shifts;

        // If shift is > 26, take mod 26.
        if(abs(shifts) > 26)
            shifts = shifts % 26;
        if(shifts < 0)
            shifts = message.length() + shifts;

        // for loop to encrypt the message.
        for (int i = 0; i < message.length(); ++i) {
            if (i >= shifts)
                encMessage += message[i];
        }
        for (int i = 0; i <= shifts-1; ++i) {
            encMessage += message[i];
        }
        // show the user the encrypted message.
        cout << "Encrypted message = " << encMessage << endl;
        cout << endl;

    // if the user choose number 2 the decryption will be implemented.
    }else if(choice == 2)
    {
        string message;
        string decMessage = " ";
        // take the message to decrypt.
        cout << "Enter the message you want to decrypt: ";
        cin.ignore();
        getline(cin, message);
        int shifts;
        // take the number of shifts the user want.
        cout << "Enter the number of shifts: ";
        cin >> shifts;

        // If shift is > 26, take mod 26.
        if(abs(shifts) > 26)
            shifts = shifts % 26;
        if(shifts < 0)
            shifts = message.length() + shifts;

        // for loop to decrypt the message by shifting the characters.
        for (int i = message.length()-(shifts); i < message.length(); ++i) {
            decMessage += message[i];
        }
        for (int i = 0; i <= message.length()-shifts-1; ++i) {
            decMessage += message[i];
        }

        // show the user the decrypted message.
        cout << "Decrypted message = " << decMessage << endl;
        cout << endl;
    }
}

// function for Vignere Cipher.
void VignereCipher(){
    string message, encMessage = "", keyWord, keyWord2 = "", decMessage = " ";
    int choice;
    cout << endl;
    // let the user choose cipher or decipher.
    cout << "What do you like to do?\n1- Cipher a message\n2- Decipher a message" << endl;
    cout << endl;
    cout << "Choose a number(1 or 2): ";
    cin >> choice;

    // if the user choose 1, encryption will be implemented.
    if (choice == 1)
    {
        // take the message for encryption.
        cout << "Enter the message you want to encrypt: ";
        cin.ignore();
        getline(cin, message);

        //take the keyword.
        cout << "Enter the Key Word: ";
        cin >> keyWord;

        // if the keyword length < message length, we should add the word to itself again until it's length > message length.
        while(keyWord.length()< message.length()){
            keyWord += keyWord;
        }

        // for loop to make sure that the length of keyword = length of message by adding each character in keyword in a new variable
        // until the the length of keyword = length of message.
        for(int i = 0; i < message.length(); i++){
            keyWord2 += toupper(keyWord[i]);
        }

        // for loop to encrypt each character.
        for(int i = 0; i < message.length(); i++){
            // make sure that spaces and numbers not encrypted.
            if(message[i] == ' ' || isdigit(message[i]))
                encMessage += message[i];
            else
                // otherwise this equation will be implemented to encrypt each character.
                encMessage += char(((int(message[i]) + int(keyWord2[i]))% 26)+65);
        }

        // show the user the encrypted message.
        cout << "Encrypted Message: " << encMessage << endl;
        cout << endl;
        }

        // if the user choose 2, decryption will be implemented.
        else if(choice == 2)
        {
            // take the message for decryption.
            cout << "Enter the message you want to decrypt: ";
            cin.ignore();
            getline(cin, message);
            // take the key word.
            cout << "Enter the Key Word: ";
            cin >> keyWord;

            // if the keyword length < message length, we should add the word to itself again until it's length > message length.
            while(keyWord.length()< message.length()){
            keyWord += keyWord;
            }

            // for loop to make sure that the length of keyword = length of message by adding each character in keyword in a new variable
            // until the the length of keyword = length of message.
            for(int i = 0; i < message.length(); i++){
                keyWord2 += toupper(keyWord[i]);
            }

            // for loop to decrypt each character.
            for(int i = 0; i < message.length(); i++){
                // make sure that spaces and numbers not encrypted.
                if(message[i] == ' ' || isdigit(message[i]))
                    decMessage += message[i];
                else
                    // otherwise this equation will be implemented to decrypt each character.
                    decMessage += (char)((((message[i] - 'A') - (keyWord2[i] -'A')) + 26) % 26) + 'A';
            }
            // show the user the decrypted message.
            cout << "Decrypted Message: " << decMessage;
            cout << endl;
        }
}

// function for Baconian Cipher
void BaconianCipher(){
    //this is the dictionary i am going to use to call the value when encrypting and call the key when decrypting
    map<char,string> cipherbaconiandictionary{
        {'a',"aaaaa"},
        {'b',"aaaab"},
        {'c',"aaaba"},
        {'d',"aaabb"},
        {'e',"aabaa"},
        {'f',"aabab"},
        {'g',"aabba"},
        {'h',"aabbb"},
        {'i',"abaaa"},
        {'j',"abaab"},
        {'k',"ababa"},
        {'l',"ababb"},
        {'m',"abbaa"},
        {'n',"abbab"},
        {'o',"abbba"},
        {'p',"abbbb"},
        {'q',"baaaa"},
        {'r',"baaab"},
        {'s',"baaba"},
        {'t',"baabb"},
        {'u',"babaa"},
        {'v',"babab"},
        {'w',"babba"},
        {'x',"babbb"},
        {'y',"bbaaa"},
        {'z',"bbaab"},
        {' '," "}
};
    string word, sentence;
    int choice;
    cout << endl;
    cout << "What do you like to do?\n1- Cipher a message\n2- Decipher a message" << endl;
    cout << endl;
    cout << "Choose a number(1 or 2): ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "please enter the word you want to encrypt without spaces: ";
        cin >> word;
        for (char letter: word) {
            cout << cipherbaconiandictionary[tolower(letter)] << " ";
        }
    }
    else if(choice == 2)
    {
        string code;
        istringstream scin(" ");
        cout<<"please enter the message you want to decrypt: ";
        cin.ignore();
        getline(cin,code);
        scin.str(code);
        scin>>sentence ;
        while(scin){
            for ( char letter = 97; letter<122; letter++){
                if  (cipherbaconiandictionary[letter] == sentence){
                    cout<<letter;
            }
        }
        scin>>sentence;
    }
    }
    cout << endl;
    system("pause>0");
}

// function for Morse Code.
void MorseCode(){
    string word, sentence;
    //this is the dictionary i am going to use to call the value when encrypting and call the key when decrypting
    map<char,string> cipher_morse_dictionary{
        {'a',".-"},
        {'b',"-..."},
        {'c',"-.-."},
        {'d',"-.."},
        {'e',"."},
        {'f',"..-."},
        {'g',"--."},
        {'h',"...."},
        {'i',".."},
        {'j',".---"},
        {'k',"-.-"},
        {'l',".-.."},
        {'m',"--"},
        {'n',"-."},
        {'o',"---"},
        {'p',".--."},
        {'q',"--.-"},
        {'r',".-."},
        {'s',"..."},
        {'t',"-"},
        {'u',"..-"},
        {'v',"...-"},
        {'w',".--"},
        {'x',"-..-"},
        {'y',"-.--"},
        {'z',"--.."},
        {' ',"     "}
};
    int choice;
    cout << endl;
    cout << "What do you like to do?\n1- Cipher a message\n2- Decipher a message" << endl;
    cout << endl;
    cout << "Choose a number(1 or 2): ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "please enter the word you want to encrypt without spaces: ";
        cin >> word;
        for (char letter: word) {
            letter = tolower(letter);
            cout << cipher_morse_dictionary[letter] << " ";
        }
    }
    else if(choice == 2)
    {
       string code;
        istringstream scin(" ");
        cout<<"please enter the message you want to decrypt: ";
        cin.ignore();
        getline(cin,code);
        scin.str(code);
        scin>>sentence ;
        while(scin){
            for ( char letter = 97; letter<122; letter++){
                if  (cipher_morse_dictionary[letter] == sentence){
                    cout<<letter;
                }
            }
            scin>>sentence;
        }
    }
    cout << endl;
}

// function for Polybius Square Cipher
void PolybiusSquareCipher(){
    int num1, num2, num3, num4, num5;
    string message, encMessage = "", decMessage = "";

    // the table of the letters.
    char table [6][6] = {{' ',' ',' ',' ',' ',' '},{' ','A','B','C','D','E'},{' ','F','G','H','I','K'},{' ','L','M','N','O','P'},{' ','Q','R','S','T','U'},{' ','V','W','X','Y','Z'}};

    // let the user to choose to cipher or decipher.
    int choice;
    cout << endl;
    cout << "What do you like to do?\n1- Cipher a message\n2- Decipher a message" << endl;
    cout << endl;
    cout << "Choose a number(1 or 2): ";
    cin >> choice;

    // if user choose 1, encryption will be implemented
    if (choice == 1)
    {
        // take the key of numbers for the encryption.
        cout << "Enter the key of numbers you want to encrypt the message(5 NUMBERS): ";
        cin >> num1 >> num2 >> num3 >> num4 >> num5;

        // assign the key of numbers the user entered in the table.
        // we should add character '0' to each number to convert it to char, so we can add the numbers in the table of type char.
        table[0][1] = '0' + num1;
        table[0][2] = '0' + num2;
        table[0][3] = '0' + num3;
        table[0][4] = '0' + num4;
        table[0][5] = '0' + num5;
        table[1][0] = '0' + num1;
        table[2][0] = '0' + num2;
        table[3][0] = '0' + num3;
        table[4][0] = '0' + num4;
        table[5][0] = '0' + num5;

        // take the message to encrypt.
        cout << "Enter the message you want to encrypt: ";
        cin.ignore();
        getline(cin, message);

        // for loop to encrypt the message.
        for(int i = 0; i < message.length(); i++){
            // if the letter is J we automatically will add the number in table[2][0] and table[0][4] in the new variable(encMessage)
            // J/I are supposed to be in the same place in the table, but we can't add two elements in the same index in the 2D array.
            if(toupper(message[i]) == 'J'){
                encMessage += table[2][0];
                encMessage += table[0][4];
            }

            // make sure not to encrypt the space.
            if (message[i] == ' ')
                encMessage += " ";

            // for loop to replace each character with two numbers according to the table.
            // r indicates to rows and c indicates to columns.
            for(int r = 1; r < 6; r++){
                for(int c = 1; c < 6; c++){
                    if(toupper(message[i]) == table[r][c]){
                        encMessage += table[r][0];
                        encMessage += table[0][c];
                    }
                }
            }
        }
        // show the user the encrypted message.
        cout << "Encrypted Message: " << encMessage;
        cout << endl;
    }

    // if the user choose number 2, the decryption will be implemented.
    else if(choice == 2)
    {
        // take the key of numbers for decryption.
        // it should be the same numbers used in encryption to output the correct message.
        cout << "Enter the key of numbers you want to decrypt the message(5 NUMBERS,\nand make sure to be the same numbers used in encryption): ";
        cin >> num1 >> num2 >> num3 >> num4 >> num5;

        // assign the key of numbers the user entered in the table.
        // we should add character '0' to each number to convert it to char, so we can add the numbers in the table of type char.
        table[0][1] = '0' + num1;
        table[0][2] = '0' + num2;
        table[0][3] = '0' + num3;
        table[0][4] = '0' + num4;
        table[0][5] = '0' + num5;
        table[1][0] = '0' + num1;
        table[2][0] = '0' + num2;
        table[3][0] = '0' + num3;
        table[4][0] = '0' + num4;
        table[5][0] = '0' + num5;

        // take the message from the user for decryption.
        cout << "Enter the message you want to decrypt(WITHOUT SPACES): ";
        cin.ignore();
        getline(cin, message);

        // replace every 2 numbers with character according to the table.
        for(int i = 0; i < message.length(); i+=2){
            // convert the two numbers to string to compare it with numbers in the table.
            string newmessage = "";
            newmessage += message[i];
            newmessage += message[i+1];

            // r indicates to rows and c indicates to columns.
            for(int r = 0; r < 5; r++){
                for(int c = 1; c < 6; c++){
                    string num = "";
                    num += table[0][r+1];
                    num += table[c][0];
                    if(newmessage == num)
                        decMessage += table[r+1][c];
                }
            }
        }
        // show the user the decrypted message.
        cout << "Decrypted Message: " << decMessage;
        cout << endl;
    }
}

// function for Atbash Cipher.
void AtbashCipher(){
    int choice;
    cout << endl;
    // let the user choose cipher or decipher.
    cout << "What do you like to do?\n1- Cipher a message\n2- Decipher a message" << endl;
    cout << endl;
    cout << "Choose a number(1 or 2): ";
    cin >> choice;

    // if the user choose 1, encryption will be implemented.
    if (choice == 1)
    {
        string Alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string msg;
        cout << "Please enter a text to encrypt it: ";
        cin.ignore();
        getline(cin, msg);

        for(int i=0;i<msg.length();i++){
            msg[i] = toupper(msg[i]);
        }

        string cipher ="" ;
        for(int i = Alpha.length()-1;i>-1;i--){
            cipher += Alpha[i];
        }
        string encrypt = "";
        for(int i=0;i<msg.length();i++){
            if(msg[i]==32){
                encrypt += " ";
            }
            else{
                for(int l=0;l<Alpha.length();l++){
                    if(msg[i]==Alpha[l]){
                        encrypt += cipher[l];
                        break;
                    }
                }
            }
        }
        cout<<"Encrypted Text:"<<encrypt;
        cout << endl;
    }

    else if(choice == 2)
    {
        string Alpha = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
        string msg;
        cout << "Please enter a text to decrypt it: ";
        cin.ignore();
        getline(cin, msg);

        for(int i=0;i<msg.length();i++){
            msg[i] = toupper(msg[i]);
        }

        string decipher ="" ;
        for(int i = Alpha.length()-1;i>-1;i--){
            decipher += Alpha[i];
        }
        string decrypt = "";
        for(int i=0;i<msg.length();i++){
            if(msg[i]==32){
                decrypt += " ";
            }
            else{
                for(int l=0;l<Alpha.length();l++){
                    if(msg[i]==Alpha[l]){
                        decrypt += decipher[l];
                        break;
                    }
                }
            }
        }
        cout<<"Decrypted Text:"<<decrypt;
        cout << endl;
    }
}

// function for void XOR Cipher.
void XORCipher(){
    int choice;
    cout << endl;
    // let the user choose cipher or decipher.
    cout << "What do you like to do?\n1- Cipher a message\n2- Decipher a message" << endl;
    cout << endl;
    cout << "Choose a number(1 or 2): ";
    cin >> choice;

    // if the user choose 1, encryption will be implemented.
    if (choice == 1)
    {
        int key_i = 0;
        string msg;
        string key;
        string result;
        cout << "Please enter a text to encrypt it: " << endl;
        cin.ignore();
        getline(cin, msg);
        cout << "Please enter a key: " << endl;
        cin >> key;
        cout << "Encrypted Text:";
        for (int i = 0; i < msg.length(); i++) {
            result = msg[i] ^ key[key_i];
            cout << result;
        }
        //Hexadecimal
        string encrypHexa = "";
        stringstream res;
        for (int i = 0; i < msg.length(); i++) {
            int result = msg[i] ^ key[key_i];
            res << hex << setfill('0') << std::setw(2) << (int) result;
            key_i++;
            if (key_i >= key.length()) {
                key_i = 0;
            }
            cout << "";
        }
        cout << "\n";
        res >> encrypHexa;
        cout << "Hexa:" << encrypHexa << endl;
        cout << endl;
    }
    else if(choice == 2)
    {
        //input message
        string msg;
        cout << "Please enter a text to decrypt in hexadecimal:"<<endl;
        cin.ignore();
        getline(cin, msg);
        //input key
        string key;
        cout << "Please enter a key:"<<endl;
        cin >> key;
        //convert from hex
        string hex_to = "";
        for (int i = 0; i < msg.length() - 1; i += 2) {
            string output = msg.substr(i, 2);
            int decimal = strtol(output.c_str(), NULL, 16);
            hex_to += (char) decimal;
        }
        string result = "";
        int key_i = 0;
        for (int i = 0; i < hex_to.length(); i++) {
            result +=  hex_to[i] ^ key[key_i];
        }
        cout << result << endl;
        cout << endl;
    }
}
