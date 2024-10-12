#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortingBalls {
private:
    vector<bool> is_available;
    const int total_number_of_balls;
public:
    SortingBalls(int number_of_balls) : total_number_of_balls(number_of_balls) {
        is_available = vector<bool>(number_of_balls, false);
    }

    void addBall(int number) {
        if(number < 0 || number >= total_number_of_balls) {
            cout << "Please provide valid ball number between 0 and " << (total_number_of_balls - 1) << "." << endl;
            return;
        }

        is_available[number] = true;
    }

    vector<int> getBalls() {
        vector<int> balls;

        for(int i = 0; i < total_number_of_balls; i++) {
            if(is_available[i]) {
                balls.push_back(i);
            }
        }

        return balls;
    }
};

class SortingCharacters {
public:
    static string sortCharacter(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);

        vector<int> freq(26, 0);
        for(char ch : str) {
            if('a' <= ch && ch <= 'z') {
                int idx = ch - 'a';
                freq[idx]++;
            }
        }

        string res;

        for(int i = 0; i < 26; i++) {
            while(freq[i]--) {
                char ch = 'a' + i;
                res += ch;
            }
        }

        return res;
    }
};

void showBalls(const vector<int> &balls) {
    cout << "Current balls : ";
    for(int b : balls) {
        cout << b << " ";
    }
    cout << endl;
}

int main() {
    cout << "1. Sorting Balls" << endl;
    cout << "2. Sorting Characters" << endl;
    cout << "Please enter option 1 or 2 : ";
    int option;
    cin >> option;

    cin.ignore(1000, '\n');
    if(option == 1) {
        int total;
        cout << "Enter total number of balls : ";
        cin >> total;
        if(total < 0) {
            cerr << "Number : " << total << " is not valid. Please give positive." << endl;
            return 1;
        }

        SortingBalls sorting_balls(total);
        showBalls(sorting_balls.getBalls());

        int number = 0;
        while (number >= 0)
        {
            cout << "Please enter negative number to exit!\nEnter ball number : ";
            cin >> number;
            sorting_balls.addBall(number);
            showBalls(sorting_balls.getBalls());
        }
    } else if(option == 2) {
        cout << "Enter sentence to sort : ";
        string str;
        getline(cin, str);

        string res = SortingCharacters::sortCharacter(str);
        
        cout << "Result : " << res << endl;
    } else {
        cout << "You entered invalid option." << endl;
    }

    return 0;
}