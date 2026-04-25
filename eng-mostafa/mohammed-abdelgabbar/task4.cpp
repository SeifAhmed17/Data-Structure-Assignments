Node* removeAt(Node* head, int x) {
    if (x == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    for (int i = 0; i < x - 1; i++)
        temp = temp->next;

    Node* del = temp->next;
    temp->next = del->next;
    delete del;

    return head;
}