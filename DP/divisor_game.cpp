// ### Approach to Solve the Problem

// 1. **Understand the Problem Dynamics**:
//    - Alice and Bob alternate turns.
//    - A player chooses a divisor \( x \) of \( n \), such that \( 0 < x < n \), and replaces \( n \) with \( n - x \).
//    - If a player cannot make a move, they lose.

// 2. **Key Observations**:
//    - The game's outcome depends on whether the current number \( n \) is even or odd:
//      - If \( n \) is **even**, Alice can always pick \( x = 1 \) (a divisor of \( n \)), leaving an odd \( n - x \) for Bob.
//      - If \( n \) is **odd**, any divisor \( x \) chosen will leave \( n - x \) as even for Alice.
//    - Since even and odd numbers alternate, Alice has an advantage if \( n \) is even at the start.

// 3. **Optimal Strategy**:
//    - If \( n \) is even, Alice will win:
//      - She can always leave an odd number for Bob, ensuring Bob loses eventually.
//    - If \( n \) is odd, Alice will lose:
//      - Whatever move she makes, she will leave an even \( n \) for Bob, who will then win by following the optimal strategy.

// 4. **Implementation Logic**:
//    - Simply check if \( n \) is even:
//      - Return `true` if \( n \% 2 == 0 \), meaning Alice will win.
//      - Return `false` otherwise, meaning Bob will win. 

// This approach leverages mathematical observations and avoids complex simulations or recursive calculations, ensuring a time complexity of \( O(1) \).


class Solution {
public:

    bool divisorGame(int n) {
        if(n%2==0){
            return true;
        }
        return false;
    }
};