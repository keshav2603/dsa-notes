#include <iostream>
#include <vector>
using namespace std;
class element
{
private:
    int row;
    int column;
    int num;

public:
    element(int row, int column, int num)
    {
        this->column = column;
        this->row = row;
        this->num = num;
    }
    int getColumn()
    {
        return column;
    }
    int getNum()
    {
        return num;
    }
    int getRow()
    {
        return row;
    }
};
class sparse
{
private:
    int totalRow;
    int totalColumn;
    int totalNum;
    vector<element> matrix;

public:
    sparse(int totalRow, int totalColumn, int totalNum)
    {
        this->totalColumn = totalColumn;
        this->totalRow = totalRow;
        this->totalNum = totalNum;
    }
    vector<element> getMatrix()
    {
        return matrix;
    }
    int getTotalColumn()
    {
        return totalColumn;
    }
    int getTotalNum()
    {
        return totalNum;
    }
    int getTotalRow()
    {
        return totalRow;
    }
    void create()
    {
        while (totalNum > matrix.size())
        {
            int row;
            int column;
            int num;
            cout << "enter row column and the element" << endl;
            cin >> row >> column >> num;

            element e1(row, column, num);
            matrix.push_back(e1);
        }
    }
    void display()
    {
        for (auto &e : matrix)
        {
            cout << "Row: " << e.getRow() << ", Column: " << e.getColumn() << ", Element: " << e.getNum() << endl;
        }
    }
};
void sumSparse(sparse s1, sparse s2)
{
    // creating new sparse as sum
    // parimeter of row was give as the greater row of the two sparse same as column
    sparse sum(max(s1.getTotalRow(), s2.getTotalRow()), max(s1.getTotalColumn(), s2.getTotalColumn()), s1.getTotalNum() + s2.getTotalNum());

    int i = 0;
    int j = 0;
    while (i < s1.getMatrix().size() || j < s2.getMatrix().size())
    {
        int r1 = s1.getMatrix()[i].getRow();    // row of first element of s1
        int r2 = s2.getMatrix()[j].getRow();    // row of first element of s2
        int c1 = s1.getMatrix()[i].getColumn(); // column of first element of s1
        int c2 = s2.getMatrix()[j].getColumn(); // column of first element of s2
        int n1 = s1.getMatrix()[i].getNum();    // number of first element of s1
        int n2 = s2.getMatrix()[j].getNum();    // number of first element of s2
        if (r1 == r2)
        {
            if (c1 == c2)
            {
                element e(r1, c1, n1 + n2);
                sum.getMatrix().push_back(e);
                i++;
                j++;
            }
            else if (c1 < c2)
            {
                element e(r1, c1, n1);
                sum.getMatrix().push_back(e);
                i++;
            }
            else
            {
                element e(r2, c2, n2);
                sum.getMatrix().push_back(e);
                j++;
            }
        }
        else if (r1 < r2)
        {
            element e(r1, c1, n1);
            sum.getMatrix().push_back(e);
            i++;
        }
        else
        {
            element e(r2, c2, n2);
            sum.getMatrix().push_back(e);

            j++;
        }
    }
    for (auto &e : sum.getMatrix())
    {
        cout << "Row: " << e.getRow() << ", Column: " << e.getColumn() << ", Element: " << e.getNum() << endl;
    }
}
int main()
{
    int rowNo, columnNo, totalNum;
    cout << "Enter the number of rows, columns, and total number of elements: ";
    cin >> rowNo >> columnNo >> totalNum;

    sparse mySparse(rowNo, columnNo, totalNum);
    mySparse.create();

    cout << "Enter the number of rows, columns, and total number of elements for second: ";
    cin >> rowNo >> columnNo >> totalNum;
    sparse mySparse2(rowNo, columnNo, totalNum);
    mySparse2.create();
    sumSparse(mySparse, mySparse2);

    return 0;
}