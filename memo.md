# step1

3 種類のかっこがあるので,三つの flag を用いる
引数を一文字ずつ見ていく

```
s = "([)]"
```

の場合に通らないので括弧の順番を保存したい
string に,開いたかっこを追加していき閉じたら括弧を削除する方針

s = "(([]){})" の時通らなかった

```
class Solution {
public:
    bool isValid(string s) {
        bool a = true, b = true, c = true;
        string open;
        for (int i = 0; i < s.size(); i++) {
             if (s[i] == '(') {
                a = false;
                val += s[i];
             }
             if (s[i] == '[') {
                b = false;
                val += s[i];
             }
             if (s[i] == '{') {
                c = false;
                val += s[i];
             }

             if (!a && s[i] == ')' &&  val.back() == '(') {
                a = true;
                val.pop_back();
                continue;
             }
             if (!b && s[i] == ']' &&  val.back() == '[') {
                b = true;
                val.pop_back();
                continue;
             }
             if (!c && s[i] == '}' &&  val.back() == '{') {
                c = true;
                val.pop_back();
                continue;
             }

             if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                return false;
             }
        }
        if (a && b && c && val.empty()) {
            return true;
        } else {
            return false;
        }

    }
};
```

bool は消して、開きかっこを保存する文字列のみで判断すればいいのでは
accept された

# step2

変数名を open から open_brackets に変更
他の方の PR を見る
https://github.com/kunimomo/arai60/pull/8/changes
自分のコードでは string を stack として使っていたが stack<char>の方が
stack を使っていることが明示的だと思ったので取り入れる
unordered_map の使い方が参考になった,key と value で開き括弧と閉じ括弧を保存しておけば contains で確認できるため,if 文を簡潔に書ける
