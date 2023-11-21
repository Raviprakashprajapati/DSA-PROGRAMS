package BST;

public class BuildBst {

    static class Node{
        int data;
        Node left;
        Node right;

        Node(int data){
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    public static void inorder(Node root){
        if(root==null) return;

        inorder(root.left);
        System.out.print(root.data+" ");
        inorder(root.right);
    }

    public static Node insert(Node root,int value){
        if(root==null){
            root = new Node(value);
            return root;
        }

        if(root.data>value){
            //leftSubtree
           root.left =  insert(root.left,value);
        }else{
            root.right = insert(root.right,value);
        }
        return root;


    }
    
    public static boolean search(Node root,int data){

    if(root==null){
        return false;
    }

    if(root.data>data){
        return search(root.left, data);
    }
    else if(root.data==data){
        return true;
    }
    else {
        return search(root.right, data);
    }



   }
    
    public static Node delete(Node root,int data){
        if(root.data>data){
            root.left = delete(root.left, data);
        }
        else if(root.data<data){
            root.right = delete(root.right, data);
        }
        else{//root.data==data
            //case 1 //leaf Node
            if(root.left==null && root.right==null) return null;

            //case 2
            if(root.left==null){
                return root.right;
            }else if(root.right==null){
                return root.left;
            }


            //case 3
            Node inSuc = inorderSucc(root.right);
            root.data = inSuc.data;
           root.right =  delete(root.right, inSuc.data );

        }
        return root;
    }

    public static Node inorderSucc(Node root){
        while (root.left != null) {
            root = root.left;
        }
        return root;
    }
    
    public static void main(String[] args) {
    System.out.println("-----------------------------------\n");
        
       
    int node[] = {5,1,3,4,2,7};
    Node root = null;
    for (int i : node) {
            root = insert(root, i);
    }
    inorder(root);
    // System.out.println(search(root, 7));
        










































































        System.out.println("\n-----------------------------------");
    }
    
}
