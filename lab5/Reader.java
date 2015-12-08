public class Reader extends Worker {

    public Reader(int threadId, SharedMessageStorage messageStorage, QueueManager queueManager) {
        super(threadId, messageStorage, queueManager);
    }

    @Override
    public void run() {
        while(true) {
            synchronized(getMessageStorage()) {
                waitForTurn();

                System.out.println("The message is: " + getMessageStorage().getMessage());

                getQueueManager().moveToNext();

                fallAsleep();
            }
        }
    }

}