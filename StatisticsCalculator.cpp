#include <bits/stdc++.h>
using namespace std;

const string updates = "UPDATES:\nverFINAL\n--clearing screen is now a proper function\nver1.3.5.1 final\n--in ver1.3.2 Bob's name was in lowercase\nver1.3.5 final\n--Bob gets a promotion :D\n  Everyone say *Thank you Bob*!\nver1.3.4\n--very minor change in the mod check\nver1.3.3\n--added STATS for cleaner UI\n--Overall more polished now\nver1.3.2\n--now our buddy Bob is employed :D\nver1.3.1\n--fixed the arithavg giving wrong answer\nver1.3\n--now you can input -1 to quit the calculator\n--the code will now run until you manually close it\nver1.2\n--added support for decimals\n--added binary search & now will print out all mod\n  if there's more than one\nver1.1\n--first full release\n--major bug fixes\n 1) quartile bug fixed\n 2) fixed the logic of the functions\nver1.0\n--release 1.0 \n--main features include:\n  1) calculating mod, median, arithmetic average, and deviation :D";

void clearScreen(){
    system("clear");
}
//q3calc gets the Q3(upper bound)
float q3calc(float c[], int sizee){
    if(sizee % 2 == 0){
        return (c[sizee/2] + c[sizee/2 - 1]) / 2.0;
    } else {
        return c[sizee/2];
    }
}
//q1calc gets the Q1(lower bound)
float q1calc(float a[], int q1){
    if(q1 % 2 == 0){
        return (a[q1/2] + a[q1/2 - 1]) / 2.0;
    } else {
        return a[q1/2];
    }
}
//q2calc gets the median
float q2calc(float b[], int n){
    if(n % 2 == 0){
        return (b[n/2] + b[n/2 - 1]) / 2.0;
    } else {
        return b[n/2];
    }
}
//binary search (MY FIRST ONE :O :D :), nice)
bool binary(const vector<float> &mod, float mogging){
    int l = 0, r = mod.size() - 1;

    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(mod[mid] == mogging) return true;
        else if(mod[mid] < mogging) l = mid + 1;
        else r = mid - 1;
    }

    return false;
}

int main(){
    //declaring variables
    int n, q1, q3, dummy = 0;
    float arithavg = 0, q1f, q3f;

    //main loop
    while(dummy == 0){
        cout << "=====" << endl;
        cout << "Enter -1 to quit, Enter -2 for updates" << endl;
        cin >> n;

        //here resides Bob :D
        if(n == -1){
            cout << "Bye :D" << endl;
            break;
        } else if(n == -2){
            clearScreen();
            cout << updates << endl;
            cout << "=====" << endl;
            cout << "Enter -1 to quit" << endl;
            cin >> n;
            if(n == -1){
                cout << "Bye :D" << endl;
                break;
            }
        }

        //putting your numbers into the array
        float b[n];
        for(float &i : b) cin >> i;
        clearScreen();

        //Cleans out the screen and shows the numbers you just entered
        cout << "Showing STATS for: " << endl;
        for(float i : b) cout << i << " ";
        cout << endl;

        //Calculating the Mod
        vector<int> dp(n, 1);

        sort(b, b+n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((b[i] == b[j]) && (i != j)){
                    dp[i] += 1;
                }
            }
        }
        
        vector<float> mod;
        float mogging;

        if(*max_element(dp.begin(), dp.end()) == 1){
            cout << "Mod: None" << endl;
        } else {
            for(int i = 0; i < n; i++){
                if(dp[i] == *max_element(dp.begin(), dp.end())){
                    mogging = b[i];
                    if(!binary(mod, mogging)) mod.push_back(mogging);
                }
            }
            cout << "Mod: ";
            for(float i : mod) cout << i << " ";
            cout << endl;
        }

        //Calculating the Median
        cout << "Median: " << q2calc(b, n) << endl;

        for(int i = 0; i < n; i++){
            arithavg += b[i];
        }

        //Calculating the Average
        cout << "Arithmetic Average: " << arithavg / n << endl;
        arithavg = 0;

        //Calculating the Range
        cout << "Average Deviation: " << *max_element(b, b+n) - *min_element(b, b+n) << endl;

        //Here the Quartile 1 and 3 are calculated using the functions q1calc, and q2calc
        if(n % 2 == 0){
            q3 = n/2; 
        } else {
            q3 = n/2 + 1;
        }

        q1 = n/2;

        int sizee = n - q3;
        float c[sizee], a[q1];

        for(int i = q3; i < n; i++){
            c[i-q3] = b[i];
        }

        for(int i = 0; i < q1; i++){
            a[i] = b[i];
        }

        //And returns the IQR
        cout << "Quartile: " << q3calc(c, sizee) - q1calc(a, q1) << endl;
        cout << endl;
    }

    return 0;
}
