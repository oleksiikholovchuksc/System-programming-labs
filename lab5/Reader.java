public class Reader extends MyThread {

    public Reader(int threadId, Object sharedObject, QueueManager queueManager) {
        super(threadId, sharedObject, queueManager);
        System.out.println("Reader constructor called.");
    }

    @Override
    public void run() {
        System.out.println("Running the reader...");
    }

}