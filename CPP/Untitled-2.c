/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    vector<vector<int>> grid;
    int n;

    Node* getRoot(int xpos, int ypos, int xlen, int ylen){
        if (xpos+1 == xlen){
            int one = grid[xpos][ypos];
            bool oneval = one==1;
            return new Node(oneval, true);
        }

        int xmid = (xpos + xlen) >> 1;
        int ymid = (ypos + ylen) >> 1;

        Node* topLeft = getRoot(xpos, ypos, xmid, ymid);
        Node* topRight = getRoot(xpos, ymid, xmid, ylen);
        Node* bottomLeft = getRoot(xmid, ypos, xlen, ymid);
        Node* bottomRight = getRoot(xmid, ymid, xlen, ylen);

        if (topLeft->isLeaf
            && topRight->isLeaf
            && bottomLeft->isLeaf
            && bottomRight->isLeaf)
        {
            if (topLeft->val == topRight->val
                && topRight->val == bottomLeft->val
                && bottomLeft->val == bottomRight->val)
            {
                return new Node(topLeft->val, true);
            }
        }

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
public:
    Node* construct(vector<vector<int>>& _grid) {
        grid = _grid;
        n = grid.size();

        return getRoot(0, 0, n, n);
    }
};