#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int main() {
    bool finished = false;
    int choice = 0;
    string expense_name = "";
    float amount = 0;
    vector<string> expense_list = {};
    vector<float> amount_list = {};
    int entry = 0;
    float spent = 0;

    while(!finished) {
        cout << "=== Expense Manager ===" << endl;
        cout << "1. Add expense" << endl;
        cout << "2. Show all expenses" << endl;
        cout << "3. Total spent" << endl;
        cout << "4. Save" << endl;
        cout << "5. Load" << endl; /// Doesnn't work for now, TO:DO WILL BE FIXED
        cout << "6. Exit" << endl;
        cout << "9. Remove the expenses" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1){
            cout << endl << "Enter expense name: ";
            getline(cin, expense_name);
            cout << endl << "Enter amount: ";
            cin >> amount;
            expense_list.push_back(expense_name);
            amount_list.push_back(amount);
            entry++;
            spent += amount;
        }
        else if (choice == 2)
        {   
            if(entry > 0){
                cout << "=== All Expenses ===" << endl;
                cout << "---------------------------" << endl;
                for (int i = 0; i < entry; i++)
                {
                    cout << endl << i + 1 << ") ";
                    cout << expense_list[i] << " - " << amount_list[i] << endl;
                }
                cout << "Total entries: " << entry << endl;
                cout << "---------------------------" << endl;
                cin.get();
            }
            else if(entry == 0){
                cout << "No entry is entered";
            }
            else{
                cout << "Wait something is ain't right";
                entry = 0;
            }
            
        }
        else if (choice == 3)
        {
            cout << "=== Total Spent ===" << endl;
            cout << "You spent: " << spent << "TL" << endl;
            cout << "Press any key to continue";
            string placeholder = "";
            cin >> placeholder;
        }
        else if (choice == 4)
        {
            ofstream expenses_text("expenses.txt");
            for (int i = 0; i < entry; i++)
            {
                expenses_text << expense_list[i] << "," << amount_list[i] << endl;
            }
            expenses_text << "TOTALS," << spent << "," << entry << endl;
            expenses_text.close();
            
            cout << "Data saved!!!";
        }
        else if (choice == 5)
        {
            expense_list.clear();
            amount_list.clear();
            entry = 0;
            spent = 0;
            
            ifstream expenses_load("expenses.txt");
            string line;
            
            while (getline(expenses_load, line))
            {
                int index = line.find(',');
                string str_expense = line.substr(0, index);
                string str_amount = line.substr(index + 1);/* The amount as a string */
                if (str_expense == "TOTALS")
                {
                    int second_comma = str_amount.find(",");
                    string total_spent = str_amount.substr(0, second_comma);
                    string total_entries = str_amount.substr(second_comma + 1);

                    spent = stof(total_spent);
                    entry = stoi(total_entries);
                }
                else
                {
                    float amount = stof(str_amount);
                    expense_list.push_back(str_expense);
                    amount_list.push_back(amount);
                }
                cout << "Data Loaded";
            }
            expenses_load.close();
        }
        else if (choice == 6)
        {
            finished = true;
        }
        else if (choice == 9)
        {
            expense_list.erase(expense_list.begin(), expense_list.end());/*.erase() can be used though but I didn't want to use.*/
            amount_list.erase(amount_list.begin(), amount_list.end());
            entry = 0;
            spent = 0;
            cout << "Removed";
        }
        else{
            cout << "Invalid command";
        }
    }
    return 0;
}