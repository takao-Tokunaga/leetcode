# step1

しばらく考え前回と似たやり方でできると思ったが解けず、解答を見る
みても理解できず紙に書いてみる
while (node != nullptr && node->next != nullptr) {
if (node->val == node->next->val) {
node->next = node->next->next;
}
node = node->next;
}

[1,1,1]などの場合に通らなかったため違う解答を参照
next を使って重複を探す

# step2

他の方の PR を見る
next を next_node に変更
while (next_node != nullptr)と書いていたが
while (next_node) でも可

# step3

3 回解いて終了
