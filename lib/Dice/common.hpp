#include <iostream>
using namespace std;


/*--- begin ---*/

class Dice {
  private:
    int front, back, up, right, bottom, left;
  public:
    Dice(int front=1, int up=2, int right=3, int left=4, int bottom=5, int back=6) {
      this->front = front;
      this->back = back;
      this->up = up;
      this->right = right;
      this->bottom = bottom;
      this->left = left;
    }

    // 上方向に転がす
    void rollUp() {
      int tmp = this->back;
      this->back   = this->up;     // 上   -> 奥
      this->up     = this->front;  // 手前 -> 上
      this->front  = this->bottom; // 下   -> 手前
      this->bottom = tmp;          // 奥   -> 下
    }

    // 下方向に転がす
    void rollDown() {
      int tmp = this->back;
      this->back   = this->bottom; // 下   -> 奥
      this->bottom = this->front;  // 手前 -> 下
      this->front  = this->up;     // 上   -> 手前
      this->up     = tmp;          // 奥   -> 上
    }

    // 右方向に転がす
    void rollRight() {
      int tmp = this->back;
      this->back = this->right;  // 右   -> 奥
      this->right = this->front; // 手前 -> 右
      this->front = this->left;  // 左   -> 手前
      this->left = tmp;          // 奥   -> 左
    }

    // 左方向に転がす
    void rollLeft() {
      int tmp = this->back;
      this->back = this->left;   // 左   -> 奥
      this->left = this->front;  // 手前 -> 左
      this->front = this->right; // 右   -> 手前
      this->right = tmp;         // 奥   -> 右
    }

    // getter
    int getFront() {
      return this->front;
    }
    int getUp() {
      return this->up;
    }
    int getRight() {
      return this->right;
    }
    int getBottom() {
      return this->bottom;
    }
    int getLeft() {
      return this->left;
    }
    int getBack() {
      return this->back;
    }
};

/*--- end ---*/
