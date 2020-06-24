
void *thread_push(void *arg) {
    int i;
    int item;
    Shared *shared = (Shared *) arg;

    for (i = 0; i < (QUEUE_LENGTH-1)/2; i++) {
        queue_push(shared->queue, 1);
    }

    pthread_exit(NULL);
}

void *test_2_thread1_push(void *arg) {
    Shared *shared = (Shared *) arg;
    sleep(1);

    queue_push(shared->queue, 1);

    pthread_exit(NULL);
}

void *test_2_thread2_pop(void *arg) {
    int i;
    int item;
    Shared *shared = (Shared *) arg;

    item = queue_pop(shared->queue);

    pthread_exit(NULL);
}

void *test_3_thread1_push(void *arg) {
    int i;
    int item;
    Shared *shared = (Shared *) arg;

    for (i = 0; i < QUEUE_LENGTH; i++) {
        queue_push(shared->queue, i);
    }

    pthread_exit(NULL);

}

void *test_3_thread2_pop(void *arg) {
    Shared *shared = (Shared *) arg;
    sleep(1);
    queue_pop(shared->queue);

    pthread_exit(NULL);
}

void thread_safety_push() {
    pthread_t child[NUM_CHILDREN];
    Shared *shared = make_shared();
    int i;
    for (i = 0; i < QUEUE_LENGTH; i++) {
        shared->queue->array[i] = 0;
    }

    child[0] = make_thread(thread_push, shared);
    child[1] = make_thread(thread_push, shared);

    for (i = 0; i < NUM_CHILDREN; i++) {
        join_thread(child[i]);
    }

    int check = 3;
    for (i = 0; i < QUEUE_LENGTH; i++) {
        if (!(shared->queue->array[i])) {
            check--;
        }
        assert(check);
    }
}

void pop_empty_queue() {
    pthread_t child[NUM_CHILDREN];
    Shared *shared = make_shared();
    int i;
    child[0] = make_thread(test_2_thread1_push, shared);
    child[1] = make_thread(test_2_thread2_pop, shared);

    for (i = 0; i < NUM_CHILDREN; i++) {
        join_thread(child[i]);
    }
}

void push_full_queue() {
    pthread_t child[NUM_CHILDREN];
    Shared *shared = make_shared();
    int i;
    child[0] = make_thread(test_3_thread1_push, shared);
    child[1] = make_thread(test_3_thread2_pop, shared);

    for (i = 0; i < NUM_CHILDREN; i++) {
        join_thread(child[i]);
    }
}

void thread_test() {
    thread_safety_push();
    pop_empty_queue();
    push_full_queue();
}