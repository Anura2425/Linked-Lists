void selectionSort(LinkedList& list) {
    int n = list.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        Node* minNode = list.at(i);

        for (int j = i + 1; j < n; ++j) {
            Node* current = list.at(j);
            if (current->value < minNode->value) {
                minIndex = j;
                minNode = current;
            }
        }

        if (minIndex != i) {
            Node* nodeI = list.at(i);
            Node* nodeMin = list.at(minIndex);

            list.remove(minIndex);
            list.remove(i);

            list.insert(nodeMin->key, nodeMin->value, i);
            list.insert(nodeI->key, nodeI->value, minIndex);
        }
    }
}
