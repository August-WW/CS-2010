// Text message expander

#include <iostream>
#include <string>
using namespace std;

int main() {

    string userText;

    cout << "Enter text:" << endl;
    getline(cin, userText);

    cout << "You entered: " << userText << endl;

    size_t pos = userText.find("IDK");
    if (pos != string::npos) {
        userText.replace(pos, 3, "I don't know");
    }

    pos = userText.find("TTYL");
    if (pos != string::npos) {
        userText.replace(pos, 4, "talk to you later");
    }

    pos = userText.find("JK");
    if (pos != string::npos) {
        userText.replace(pos, 2, "just kidding");
    }

    pos = userText.find("TMI");
    if (pos != string::npos) {
        userText.replace(pos, 3, "too much information");
    }

    pos = userText.find("BFF");
    if (pos != string::npos) {
        userText.replace(pos, 3, "best friend forever");
    }

    cout << "Expanded: " << userText << endl;

    return 0;
}
