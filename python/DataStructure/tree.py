from queue import Queue
'''
1. inserting an element
2. Removing an element
3. Searching for an element
4. Traversing the tree

1. Finding the height of the tree
2. Find the level of a node of the tree
3. Finding the size of the entire tree
'''
class Node(object):
    '''
        1. Data
        2. Pointer to the left child
        3. Pointer to the right child
    '''
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
    def insert(self, data):
        if self.data is None:
            self.data = data
        else:
            if data <= self.data and self.left:
                self.left.insert(data)
            elif data <= self.data:
                self.left = Node(data)
            elif data > self.data and self.right:
                self.right.insert(data)
            else:
                self.right = Node(data)
    def findNode(self, data):
        if data < self.data and self.left:
            return self.left.findNode(data)
        if data > self.data and self.right:
            return self.right.findNode(data)
        return data == self.data
    def clearNode(self):
        self.data = None
        self.left = None
        self.right = None
    def findMinData(self):
        if self.left:
            return self.left.findMinData()
        else:
            return self.data

    def remove_node(self, data, parent):
        if data < self.data and self.left:
            return self.left.remove_node(data, self)
        elif data < self.data:
            return False
        elif data > self.data and self.right:
            return self.right.remove_node(data, self)
        elif data > self.data:
            return False
        else:
            if self.left is None and self.right is None and self == parent.left:
                parent.left_child = None
                self.clearNode()
            elif self.left is None and self.right is None and self == parent.right:
                parent.right_child = None
                self.clearNode()
            elif self.left and self.right is None and self == parent.left:
                self.clearNode()
            elif self.left and self.right is None and self == parent.right:
                parent.right_child = self.left
                self.clearNode()
            elif self.right and self.left is None and self == parent.left:
                parent.left_child = self.right
                self.clearNode()
            elif self.right and self.left is None and self == parent.right:
                parent.right_child = self.right
                self.clearNode()
            else:
                self.data = self.right.findMinData()
                self.right.remove_node(self.data, self)

            return True
    def printTree(self):
        if self.left:
            self.left.printTree()
        print(self.data)
        if self.right:
            self.right.printTree()
    #Tree Traversal (1. DLR, 2. LDR 2. LRD) where D-Data, L-Left, R-Right)
    def preOrder(self):  #DLR
        print(self.data)
        if self.left:
            self.left.preOrder()
        if self.right:
            self.right.preOrder()
    def inOrder(self): #LDR

        if self.left:
            self.left.inOrder()
        print(self.data)
        if self.right:
            self.right.inOrder()
    def postOrder(self): #LRD
        if self.left:
            self.left.postOrder()
        if self.right:
            self.right.postOrder()
        print(self.data)
    '''
    def preorder(self,root):
        if root:
            print(root.data)
            self.preorder(root.left)
            self.preorder(root.right)
    def inorder(self, root):
        if root:
            self.inorder(root.left)
            print(root.data)
            self.inorder(root.right)
    def postorder(self, root):
        if root:
            self.postorder(root.left)
            self.postorder(root.right)
            print(root.data)
    '''


    def bfs(self):
        queue = Queue()
        queue.put(self)
        while not queue.empty():
            current_node = queue.get()
            print(current_node.data)
            if current_node.left:
                queue.put(current_node.left)
            if current_node.right:
                queue.put(current_node.right)







def dataValue():
    root = Node(50)
    root.insert(20)
    root.insert(11)
    root.insert(15)
    root.insert(45)
    root.insert(30)
    root.insert(78)
    root.printTree()

    print(root.remove_node(30, None))

    root.preOrder()
def main():
    dataValue()

if __name__=='__main__':
    main()

