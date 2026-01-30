/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
using namespace std;

string onlyConnectize(string phrase) {
    /* TODO: The next few lines just exist to make sure you don't get compiler warning messages
     * when this function isn't implemented. Delete these lines, then implement this function.
     */
    string s = toUpperCase(phrase);
    if (phrase.length()==0){
        return "";
    }
    else if(s[0]=='B' || s[0]=='C' || s[0]=='D' || s[0]=='F' || s[0]=='G' || s[0]=='H' || s[0]=='J' || s[0]=='K' || s[0]=='L'
             || s[0]=='M' || s[0]=='N' || s[0]=='P' || s[0]=='R' || s[0]=='S' || s[0]=='T' || s[0]=='V' || s[0]=='Y' || s[0]=='Z'
             || s[0]=='W' || s[0]=='X' || s[0]=='Q'){
        return s[0] + onlyConnectize(phrase.substr(1));
    }
    else{
        return onlyConnectize(phrase.substr(1));
    }
}







/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828werTych"), "WRTYCH");
    EXPECT_EQUAL(onlyConnectize("'Hi, 56Mohhm!'"), "HMHHM");
}




