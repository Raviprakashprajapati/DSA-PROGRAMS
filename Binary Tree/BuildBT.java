import java.util.LinkedList;
import java.util.Queue;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree {

    static int count = 0;
    static int index = -1;

    public Node buildTree(int node[]) {
        index++;
        // if root is null
        if (node[index] == -1)
            return null;

        Node newNode = new Node(node[index]);
        newNode.left = buildTree(node);
        newNode.right = buildTree(node);

        return newNode;

    }

    public void preorder(Node root) {
        if (root == null) {
            return;
        }
        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
    }

    public void inorder(Node root) {
        if (root == null)
            return;

        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    public void postorder(Node root) {
        if (root == null)
            return;

        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data + " ");
    }

    public void levelOrder(Node root) {
        if (root == null)
            return;

        Queue<Node> q = new LinkedList<>();
        q.add(root);
        q.add(null);

        // for quene empty
        while (!q.isEmpty()) {
            Node currentNode = q.remove();

            if (currentNode == null) {
                System.out.println();

                if (q.isEmpty()) {
                    return;
                } else {
                    q.add(null);
                }

            } else {
                System.out.print(currentNode.data + "  ");

                if (currentNode.left != null)
                    q.add(currentNode.left);
                if (currentNode.right != null)
                    q.add(currentNode.right);

            }
        }
    }

    public int countNodes(Node root) {
        if (root == null)
            return 0;

        int leftNodes = countNodes(root.left);
        int rightNodes = countNodes(root.right);

        return leftNodes + rightNodes + 1;
    }

    public int sumOfNodes(Node root) {
        if (root == null)
            return 0;

        int leftSum = sumOfNodes(root.left);
        int rightSum = sumOfNodes(root.right);

        return leftSum + rightSum + root.data;
    }

    public int height(Node root) {
        if (root == null)
            return 0;

        int leftHeight = height(root.left);
        int rightHeight = height(root.right);

        return Math.max(leftHeight, rightHeight) + 1;
    }

    public int maxDaimeter(Node root) { //on2

        if (root == null)
            return 0;

        int leftDiamenter = maxDaimeter(root.left);
        int rightDiamenter = maxDaimeter(root.right);
        int rootDiameter = height(root.left) + height(root.left) + 1;

        return Math.max(Math.max(leftDiamenter, rightDiamenter), rootDiameter);

    }


    public boolean subTree(Node root,Node subTreeRoot){

        if(root==null) return false;

        if(root.data==subTreeRoot.data){
           if(identical(root, subTreeRoot))
           {
            return true;
           }
        }
        
        return subTree(root.left, subTreeRoot) || subTree(root.right, subTreeRoot);

    }

    public boolean identical(Node root,Node root2){

        if(root==null && root2==null) return true;

        if(root==null || root2==null) return false;

        return identical(root.left, root2.left) && identical(root.right, root2.right);
    }


}

public class BuildBT {

    public static void main(String[] argv) {
        System.out.println("-------------------------------------");

        int node[] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

        BinaryTree tree01 = new BinaryTree();
        Node root = tree01.buildTree(node);

        // tree01.preorder(root);
        // tree01.inorder(root);
        // tree01.postorder(root);
        // tree01.levelOrder(root);
        // System.out.println(tree01.countNodes(root));
        // System.out.println(tree01.sumOfNodes(root));
        // System.out.println(tree01.height(root));
        // System.out.println(tree01.maxDaimeter(root));

        //Subtree of another tree
        int node2[] = {1,2,-1,-1,3,-1,-1};
        BinaryTree tree02 = new BinaryTree();
        Node root2 = tree01.buildTree(node2);
        tree02.preorder(root2);














        System.out.println("\n-------------------------------------");

    }
}