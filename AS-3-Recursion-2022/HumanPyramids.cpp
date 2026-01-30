#include "HumanPyramids.h"
#include "error.h"
#include "vector.h"
using namespace std;

/* TODO: Refer to HumanPyramids.h for more information about what this function should do.
 * Then, delete this comment.
 */
bool is(int row, int col, int h){
    if(row > h || row < 0 || col < 0 || col > row) return false;
    return true;
}

double weightHelper(int row, int col, int pyramidHeight, Vector<Vector<double>>& memo){
    if (row==0){
        return 0;
    }
    if(memo[row][col]!=-1) return memo[row][col];
    double sum=0;
    if(is(row-1, col-1, pyramidHeight)){
        sum+=weightHelper(row-1, col-1, pyramidHeight, memo)/2 + 80;
    }
    if(is(row-1, col, pyramidHeight)) sum+=weightHelper(row-1, col, pyramidHeight, memo)/2+80;
    memo[row][col]=sum;
    return sum;

}

double weightOnBackOf(int row, int col, int pyramidHeight) {
    /* TODO: Delete the next few lines and implement this function. */
    if (row < 0 || col < 0 || col > row || row > pyramidHeight) {
        error("Invalid");
    }
    Vector<Vector<double>> v(pyramidHeight+1, Vector<double>(pyramidHeight+1, -1));
    return weightHelper(row, col, pyramidHeight, v);

}




/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */














/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Check Person E from the handout.") {
    /* Person E is located at row 2, column 1. */
    EXPECT_EQUAL(weightOnBackOf(2, 1, 5), 240);
}

PROVIDED_TEST("Function reports errors in invalid cases.") {
    EXPECT_ERROR(weightOnBackOf(-1, 0, 10));
    EXPECT_ERROR(weightOnBackOf(10, 10, 5));
    EXPECT_ERROR(weightOnBackOf(-1, 10, 20));
}

PROVIDED_TEST("Stress test: Memoization is implemented (should take under a second)") {
    /* TODO: Yes, we are asking you to make a change to this test case! Delete the
     * line immediately after this one - the one that starts with SHOW_ERROR - once
     * you have implemented memoization to test whether it works correctly.
     */

    /* Do not delete anything below this point. :-) */
    /* This will take a LONG time to complete if memoization isn't implemented.
     * We're talking "heat death of the universe" amounts of time. :-)
     *
     * If you did implement memoization but this test case is still hanging, make
     * sure that in your recursive function (not the wrapper) that your recursive
     * calls are to your new recursive function and not back to the wrapper. If you
     * call the wrapper again, you'll get a fresh new memoization table rather than
     * preserving the one you're building up in your recursive exploration, and the
     * effect will be as if you hadn't implemented memoization at all.
     */
    EXPECT(weightOnBackOf(100, 50, 200) >= 10000);
}

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */
