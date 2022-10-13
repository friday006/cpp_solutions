#include <bits/stdc++.h>
using namespace std;

// Function to get the multiplicative inverse of the determinant value
int mod(int a, int m){ 
    a=a%m; 
    for(int x=-m;x<m;x++) 
       if((a*x)%m==1) 
          return x; 
    return 0;   
} 
// Function to get the mod of negative numbers
int modneg(int a, int b)
{ return (a%b+b)%b; }

// Function used to get inverse
void getCofactor(vector<vector<int>> &plainTextMatrix, vector<vector<int>> &temp, int p, int q, int n)
{
    int i = 0, j = 0;
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those
            //  element which are not in given row and
            //  column
            if (row != p && col != q)
            {
                temp[i][j++] = plainTextMatrix[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Recursive function for finding determinant of matrix. n is current dimension of plainTextMatrix.
int determinant(vector<vector<int> > &a, int n, int N){ 
    int D = 0;
    if(n==1) 
        return a[0][0]; 
    vector<vector<int> > temp(N, vector<int>(N));
    int sign = 1;
    for(int f=0;f<n;f++){ 
        getCofactor(a, temp, 0, f, n); 
        D += sign * a[0][f] * determinant(temp, n - 1, N); 
        sign = -sign; 
    }
    return D; 
} 

// Function to get adjoint of plainTextMatrix[N][N] in adj[N][N].
void adjoint(vector<vector<int>> &plainTextMatrix, vector<vector<int>> &adj)
{
    if (plainTextMatrix.size() == 1)
    {
        adj[0][0] = 1;
        return;
    }
    // temp is used to store cofactors of plainTextMatrix[][]
    int sign = 1;
    int size = plainTextMatrix.size();
    vector<vector<int>> temp(size, vector<int>(size));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // Get cofactor of plainTextMatrix[i][j]
            getCofactor(plainTextMatrix, temp, i, j, size);
            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j][i] = (sign) * (determinant(temp, size - 1,size));
        }
    }
}

// Function to calculate and store inverse, returns false if
// matrix is singular
vector<vector<int>> inverse(vector<vector<int>> &plainTextMatrix)
{
    // Find determinant of plainTextMatrix[][]
    int det = determinant(plainTextMatrix, plainTextMatrix.size(),plainTextMatrix.size());
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        return {};
    }
    det = mod(det, 26);
    // cout << det << endl;
    // Find adjoint
    int size = plainTextMatrix.size();
     vector<vector<int>> inver(size,vector<int>(size,0));
    vector<vector<int>> adj(size, vector<int>(size));
    adjoint(plainTextMatrix, adj);
    // Find Inverse using formula "inverse(plainTextMatrix) =
    // adj(plainTextMatrix)/det(plainTextMatrix)"
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // cout << adj[i][j] << " ";
            int val = (adj[i][j] * det)%26;
            inver[i][j] = val;
        }
        // cout << endl;
    }
    return inver;
}

// Function to get integer values of Matrix from a string characters
void getMatrix(vector<vector<int>> &matrix, string &text)
{
    int size = sqrt(text.size());
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        vector<int> extra;
        for (int j = 0; j < size; j++)
        {
            extra.push_back(text[index] - 'a');
            index++;
        }
        matrix.push_back(extra);
    }
}

// for converting Matrix_to_string
string matrix_to_string(vector<vector<int>> &matrix)
{
    string cipherString = "";
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cipherString += j + 'a';
        }
    }
    return cipherString;
}

// Encryption functino to encrypt the plaintext
// Multiplying the plaintext with key to get the result
vector<vector<int>> getCipherMatrix(vector<vector<int>> &plainTextMatrix, vector<vector<int>> &keyMatrix)
{
    int size = keyMatrix.size();
    vector<vector<int>> result(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int val = 0;
            for (int k = 0; k < size; k++)
            {
                val += plainTextMatrix[i][k] * keyMatrix[k][j];
            }
            result[i][j] = val % 26;
            // cout << val << " ";
        }
        cout << endl;
    }
    return result;
}

// A function to displayMatrix: 
// very useful while debugging
void displayMatrix(vector<vector<int>> &matrix)
{
    cout << "------------------------" << endl;
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    // So the main logic is to first find the cipher text from key and plainMatrix 
    // and then taking by inverse of the plainmatrix we can calculate the key
    // C = P.K
    // Taking inverse
    // (P^-1).C = K

    // Taking input of plainText
    string plainText;
    cout << "Enter the plain plainText:" << endl;
    cin >> plainText;

    // Entering key
    string key;
    cout << "Enter the key:" << endl;
    cin >> key;

    cout << "-----------" << endl;
    cout << "PlainText: " << plainText << endl;

    cout << "Key: " << key << endl;
    cout << "-----------" << endl;
    // Adding salt if size is not equal to key
    if (plainText.size() != key.size())
    {
        int sizeofplaintext = plainText.size();
        for (int i = 0; i < key.size() - sizeofplaintext; i++)
        {
            plainText += 'x';
        }
    }
    cout << endl;
    // Encryption
    cout << "PlainText Matrix" << endl;
    // Getting plainMatrix from the plainString
    vector<vector<int>> plainTextMatrix;
    getMatrix(plainTextMatrix, plainText);
    displayMatrix(plainTextMatrix);

    vector<vector<int>> keyMatrix;
    // Getting keyMatrix from the keyString
    getMatrix(keyMatrix, key);
    cout << "KeyMatrix" << endl;
    displayMatrix(keyMatrix);

    int size = plainTextMatrix.size();

    // Now encrypting the plainText and getting the ciphertext matrix
    vector<vector<int>> cipherMatrix = getCipherMatrix(plainTextMatrix, keyMatrix);
    // cout << "CipherText Matrix" << endl;
    // displayMatrix(cipherMatrix);

    // After the cipherTextMatrix getting the string
    string cipherText = matrix_to_string(cipherMatrix);
    cout << "CipherText: ";
    cout << cipherText << endl;

    // Decryption
    // Now its time to decrypt using knownplaintext attack
    cout << endl;

    // Firstly finding the inverse of plainText 
    vector<vector<int>> inversePlain = inverse(plainTextMatrix);
    cout <<  "Inverse Matrix" << endl;
    displayMatrix(inversePlain);

    // then using that inverse mutliplying the inverse to the cipherMatrix
    vector<vector<int>> result;
    for (int i = 0; i < size; i++)
    {
        vector<int> hehe;
        for (int j = 0; j < size; j++)
        {
            int val = 0;
            for (int k = 0; k < size; k++){
                val += (inversePlain[i][k] * cipherMatrix[k][j]);
            }
            hehe.push_back(modneg(val,26));
        }
        result.push_back(hehe);
    }

    cout << endl;
    // Printing the resultant matrix
    cout << "Result Matrix:" << endl;
    displayMatrix(result);

    // Extracting the key from matrix.
    cout << "Final Decrypted Key: " << matrix_to_string(result);

    return 0;
}