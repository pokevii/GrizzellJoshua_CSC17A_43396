/* 
 * This one feels totally bloated to me. Feels like I could've definitely
 * condensed this quite a bit.
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct MonthlyBudget{
    float housing, utility, expense, trnsprt, food, medical, insrnce, entertn, clothng, misc; 
};

MonthlyBudget compare(MonthlyBudget mb);
MonthlyBudget getData(MonthlyBudget mb);
void getDiff(MonthlyBudget mb, MonthlyBudget b);

int main(int argc, char** argv) {
    MonthlyBudget mb = getData(mb);
    cout << endl;
    MonthlyBudget b = compare(mb);
    getDiff(mb, b);

    return 0;
}

//Oh, boy, I don't know how to do this other than a bunch of disgusting looking if else statements.
//At least I can use the ternary operator here to reduce the amount of space it takes up.
MonthlyBudget compare(MonthlyBudget mb){
    MonthlyBudget b = {500, 150, 65, 50, 250, 30, 100, 150, 75, 50};
    
    string result = (mb.housing == b.housing) ? "Even" : (mb.housing > b.housing) ? "Over" : "Under";
    cout << "Housing " << result << endl;
    result = (mb.utility == b.utility) ? "Even" : (mb.utility > b.utility) ? "Over" : "Under";
    cout << "Utilities " << result << endl;
    result = (mb.expense == b.expense) ? "Even" : (mb.expense > b.expense) ? "Over" : "Under";
    cout << "Household Expenses " << result << endl;
    result = (mb.trnsprt == b.trnsprt) ? "Even" : (mb.trnsprt > b.trnsprt) ? "Over" : "Under";
    cout << "Transportation " << result << endl;
    result = (mb.food == b.food) ? "Even" : (mb.food > b.food) ? "Over" : "Under";
    cout << "Food " << result << endl;
    result = (mb.medical == b.medical) ? "Even" : (mb.medical > b.medical) ? "Over" : "Under";
    cout << "Medical " << result << endl;
    result = (mb.insrnce == b.insrnce) ? "Even" : (mb.insrnce > b.insrnce) ? "Over" : "Under";
    cout << "Insurance " << result << endl;
    result = (mb.entertn == b.entertn) ? "Even" : (mb.entertn > b.entertn) ? "Over" : "Under";
    cout << "Entertainment " << result << endl;
    result = (mb.clothng == b.clothng) ? "Even" : (mb.clothng > b.clothng) ? "Over" : "Under";
    cout << "Clothing " << result << endl;
    result = (mb.misc == b.misc) ? "Even" : (mb.misc > b.misc) ? "Over" : "Under";
    cout << "Miscellaneous " << result << endl;
    return b;
}

MonthlyBudget getData(MonthlyBudget mb){
    //string costs[10] = {"housing", "utilities", "household expenses", "transportation", "food", "medical", "insurance", "entertainment", "clothing", "miscellaneous"};
    
    cout << "Enter housing cost for the month:$";
    cin >> mb.housing;
    cout << endl << "Enter utilities cost for the month:$";
    cin >> mb.utility;
    cout << endl << "Enter household expenses cost for the month:$";
    cin >> mb.expense;
    cout << endl << "Enter transportation cost for the month:$";
    cin >> mb.trnsprt;
    cout << endl << "Enter food cost for the month:$";
    cin >> mb.food;
    cout << endl << "Enter medical cost for the month:$";
    cin >> mb.medical;
    cout << endl << "Enter insurance cost for the month:$";
    cin >> mb.insrnce;
    cout << endl << "Enter entertainment cost for the month:$";
    cin >> mb.entertn;
    cout << endl << "Enter clothing cost for the month:$";
    cin >> mb.clothng;
    cout << endl << "Enter miscellaneous cost for the month:$";
    cin >> mb.misc;
    return mb;
}

void getDiff(MonthlyBudget mb, MonthlyBudget b){
    float sum1 = 0, sum2 = 0;
    
    float member1[] = {mb.housing, mb.utility, mb.expense, mb.trnsprt, mb.food, mb.medical, mb.insrnce, mb.entertn, mb.clothng, mb.misc};
    for(int i = 0; i < 10; i++){
        sum1 += member1[i];
    }
    
    float member2[] = {b.housing, b.utility, b.expense, b.trnsprt, b.food, b.medical, b.insrnce, b.entertn, b.clothng, b.misc};
    for(int i = 0; i < 10; i++){
        sum2 += member2[i];
    }
    
    float diff = sum1 - sum2;
    string result = diff < 0 ? " under " : " over ";
    diff = fabs(diff);
    
    cout << fixed << showpoint << setprecision(2);
    cout << "You were $" << diff << result << "budget";
}