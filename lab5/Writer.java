public class Writer extends MyThread {

    public Writer(int threadId, Object sharedObject, QueueManager queueManager) {
        super(threadId, sharedObject, queueManager);
        System.out.println("Writer constructor called.");
    }

    @Override
    public void run() {
        System.out.println("Running the writer...");
    }

}