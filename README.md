# PropositionalCalculusFormula
The so-called propositional calculus formula is defined by a logical variable (its value is TRUE or FALSE) and logical operators ∧ (AND), ∨ (OR) and ┐ (NOT) according to certain rules consisting of the formula (contains such operations can be used ∧, ∨ and ┐ represented). Math is the order ┐, ∧, ∨, and parentheses () can be changed priorities. Given a propositional calculus formulas and all variables of value, to design a program to calculate the true value of the formula.
Claim:
(1) running the program selection menu.
(2) the use of a formula to calculate the true binary value. Firstly stack infix form of the equation becomes postfix form; then depending on the suffix forms, from the beginning of the leaf nodes corresponding binary tree structure; the final press-order traversal of the tree, find the value of each sub-tree, that is, the arrival of each node whose value has been calculated from the sub-tree when it reaches the root node, the value obtained is the truth value of the formula.
(3) Logical Argument identifier is not limited to a single letter, but may be arbitrarily long alphanumeric string.
(4) the expression of the truth table display according to the user's requirements.
The project realized under the MFC framework entered proposition calculus formulas and variables corresponding true value to true value is calculated, please see the relevant design doc document

所谓命题演算公式是指由逻辑变量（其值为TRUE 或FALSE）和逻辑运算符∧（AND）、∨（OR）和┐（NOT）按一定规则所组成的公式（蕴含之类的运算可以用∧、∨和┐来表示）。公式运算的先后顺序为┐、∧、∨，而括号（）可以改变优先次序。已知一个命题演算公式及各变量的值，要求设计一个程序来计算公式的真值。
要求：
（1）程序运行有菜单选择。
（2）利用二叉树来计算公式的真值。首先利用堆栈将中缀形式的公式变为后缀形式；然后根据后缀形式，从叶结点开始构造相应的二叉树；最后按后序遍历该树，求各子树之值，即每到达一个结点，其子树之值已经计算出来，当到达根结点时，求得的值就是公式之真值。
（3）逻辑变元的标识符不限于单字母，而可以是任意长的字母数字串。
（4）根据用户的要求显示表达式的真值表。
本项目在MFC框架下实现输入命题演算公式及其相应变量真值即可计算公式真值，相关设计请查看doc文档