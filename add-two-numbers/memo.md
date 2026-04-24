# step1

l1 に l2 を足していく方針でいきたい

ポインタどうしを加算していき、10 を超えると繰り上げを行う

二つのノードを見ていくのでそれぞれ null の場合で条件分岐しなければならない

l1 が null の時は l1 に新しく node を追加する、

連結リストの追加ができておらず accept されない

やり方がわからず調べてみる
読むだけのポインタと結果用のポインタを作成する方針でいく

かなり複雑なコードになってしまったが,accept

# step2

まずは可読性をあげれないか考えてみる
if (sum >= 10)より
new ListNode(sum % 10);
の方が良い

if (!l1) と if (!l2)で分岐していたが null の時は l1->val を 0 で扱えば良さそう
三項演算子を使ってみる

<!-- /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* result = &dummy;
        int carry = 0;
        int sum;

        while (l1 || l2) {
            int v1 = (l1 ? l1->val : 0);
            int v2 = (l2 ? l2->val : 0);

            sum = v1 + v2 + carry;

            carry = sum / 10;

            result->next = new ListNode(sum % 10);
            result = result->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
      };
      if (carry == 1) {
            result->next = new ListNode(carry);
       }
      return dummy.next;
    }
}; -->

他の方の PR を見てみる
https://github.com/Shunii85/arai60/pull/5
変数名 result では情報が少なすぎるので added に変更
while の条件に carry を追加することで最後に if (carry == 1)を書く必要がなくなる

https://github.com/liruly/leetcode/pull/7/changes
carry を bool にすると if 文が必要なので int の方が読みやすいと思った。

# step3

10 分以内に何も見ず 3 回解いて終了

空間計算量 O(n)
時間計算量 O(n)
