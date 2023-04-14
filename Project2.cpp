#include <iostream>
#include <string>

using namespace std;

struct Word {
    string english;
    string piglatin;
};

Word* splitSentence(const string words, int &size);
void convertToPigLatin(Word wordArr[], int size);
void displayPigLatin(const Word wordArr[], int size);
bool isVowel(char c);
bool isAlpha(char c);
char toLowerCase(char c);

int main() {
    string input;
    cout << "Please enter a string: ";
    getline(cin, input);

    int size;
    Word* wordArr = splitSentence(input, size);
    convertToPigLatin(wordArr, size);

    cout << "Output: ";
    displayPigLatin(wordArr, size);

    delete[] wordArr;
    return 0;
}

Word* splitSentence(const string words, int &size) {
    int wordCount = 1;
    for (char c : words) {
        if (c == ' ') {
            wordCount++;
        }
    }

    size = wordCount;
    Word* wordArr = new Word[size];
    int wordIndex = 0;
    string cleanedWord;

    for (char c : words) {
        if (c == ' ') {
            if (!cleanedWord.empty()) {
                wordArr[wordIndex].english = cleanedWord;
                cleanedWord.clear();
                wordIndex++;
            }
        } else if (isAlpha(c)) {
            cleanedWord += toLowerCase(c);
        }
    }

    if (!cleanedWord.empty()) {
        wordArr[wordIndex].english = cleanedWord;
    }

    return wordArr;
}

void convertToPigLatin(Word wordArr[], int size) {
    for (int i = 0; i < size; i++) {
        if (isVowel(wordArr[i].english[0])) {
            wordArr[i].piglatin = wordArr[i].english + "way";
        } else {
            wordArr[i].piglatin = wordArr[i].english.substr(1) + wordArr[i].english[0] + "ay";
        }
    }
}

void displayPigLatin(const Word wordArr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << wordArr[i].piglatin;
        if (i < size - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

bool isVowel(char c) {
    c = toLowerCase(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool isAlpha(char c) {
    c = toLowerCase(c);
    return (c >= 'a' && c <= 'z');
}

char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        c = c - 'A' + 'a';
    }
    return c;
}
