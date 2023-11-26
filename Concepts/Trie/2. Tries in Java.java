/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class Tries{
    private class Node{
        Character data;
        boolean isTerminal;
        HashMap<Character, Node> Children;

        Node(Character data, boolean isTerminal){
            this.data = data;
            this.isTerminal = isTerminal;
            this.Children = new HashMap<>();
        }
    }

    Tries(){
        this.root = new Node('\0', false);
        this.numOfWords = 0;
    }

    private int numOfWords;
    private Node root;

    public void addWords(String word){
        this.addWords(this.root, word);
    }
    
    public boolean searchWord(String word){
        return this.searchWord(this.root, word);
    }

    private void addWords(Node Parent, String word){
        
        // word.length is only 0 when we reached at the end of the word
        if(word.length() == 0){
            if(!Parent.isTerminal){
                Parent.isTerminal = true;
                ++this.numOfWords;
            }
            return;
        }

        Character ch = word.charAt(0);
        String ros = word.substring(1); // finding the rest of the words in the string
        Node child = Parent.Children.get(ch); // finding from the hashmap whether there is any existing child node is there or not

        // child is null means there is no such node, so need to create one
        if(child == null){
            child = new Node(ch, false);
            Parent.Children.put(ch, child);
        }

        // Recursive calls for the rest of the words
        this.addWords(child, ros);
    }

    private boolean searchWord(Node Parent, String word){
        if(word.length() == 0){
            if(Parent.isTerminal){
                return true;
            }
            else{
                // this case comes like in trie we have string 'pots' and we are searching for 'pot'
                // so if this else condition is not present then the function will return true, which should not be the case.
                return false;
            }
        }

        Character ch = word.charAt(0);
        String ros = word.substring(1);

        // checking in the hashmap of the current node, 
        // if the first character is present or not.
        Node child = Parent.Children.get(ch);

        if(child == null){
            // as child is null it means no branch is present, so word is present , so simply return false.
            return false;
        }
        return this.searchWord(child, ros);
    }

public static void main(String str[]){
    Tries trie = new Tries();
    trie.addWords("appy");
    trie.addWords("apply");
    trie.addWords("boards");

    System.out.println(trie.searchWord("apply"));
    System.out.println(trie.searchWord("ap"));
}

}
