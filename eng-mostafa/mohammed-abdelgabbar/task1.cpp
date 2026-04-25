Node* get_nth(int n) {
    Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        if (count == n)
            return temp;
        temp = temp->next;
        count++;
    }
    return NULL;
}