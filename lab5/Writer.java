import java.util.Scanner;


public class Writer extends Worker {

    public Scanner scanner;

    public Writer(int threadId, SharedMessageStorage messageStorage, QueueManager queueManager) {
        super(threadId, messageStorage, queueManager);

        scanner = new Scanner(System.in);
    }

    @Override
    public void run() {
        while(true) {
            synchronized(getMessageStorage()) {
                waitForTurn();

                System.out.print("Please enter your message: ");
                getMessageStorage().setMessage(scanner.nextLine());

                getQueueManager().moveToNext();

                fallAsleep();
            }
        }
    }

}