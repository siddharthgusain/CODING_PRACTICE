package Rippling;

import java.util.*;

class SongSystem {

    private Map<Integer,String> songs;
    private Map<Integer,Integer> songPlayCount;
    private Map<Integer, Set<Integer>> userStarredSongs;
    private Map<Integer, Queue<Integer>> userHistory;

    SongSystem() {
        songs = new HashMap<>();
        songPlayCount = new HashMap<>();
        userStarredSongs = new HashMap<>();
        userHistory = new HashMap<>();
    }

    public void addSong(int songId, String title) {
        if(songs.containsKey(songId)){
            System.out.println("Song with id: " + songId +" already present in DB");
            return;
        }
        songs.put(songId, title);
        songPlayCount.put(songId, 0);
    }

    public void playSong(int songId,int userId) {
        if(!songs.containsKey(songId)) {
            System.out.println("Song with id: " + songId +" in not present in DB");
        }
        songPlayCount.put(songId, songPlayCount.getOrDefault(songId,0) + 1);
        userHistory.computeIfAbsent(userId, k -> new LinkedList<>());

        Queue<Integer> history = userHistory.get(userId);
        if(history.size() == 5) {
            history.poll();
        }
        
        history.offer(songId);
    }

    // Star a song for a user
    public void starSong(int songId, int userId) {
        userStarredSongs.computeIfAbsent(userId, k -> new HashSet<>());
        userStarredSongs.get(userId).add(songId);
    }

    // Unstar a song for a user
    public void unstarSong(int songId, int userId) {
        if (userStarredSongs.containsKey(userId)) {
            userStarredSongs.get(userId).remove(songId);
        }
    }

    // Get the last N favorite songs played by a user
    public void getLastNFavouriteSongs(int userId) {
        if (!userHistory.containsKey(userId)) {
            System.out.println("No favorite songs for user " + userId);
            return;
        }

        Queue<Integer> history = userHistory.get(userId);
        System.out.println("Last favourite songs played by user " + userId + ":");
        for (Integer songId : history) {
            System.out.println(songs.get(songId));
        }
    }

    public void printAnalytics(){
        if(songs.isEmpty()){
            return;
        }

        if(songPlayCount.isEmpty()){
            return;
        }

        int mostPlayedSongId = -1;
        int maxPlayCount = 0;

        for(Map.Entry<Integer,Integer> song : songPlayCount.entrySet()){
            if(song.getValue() > maxPlayCount){
                maxPlayCount = song.getValue();
                mostPlayedSongId = song.getKey();
            }
        }

        if(mostPlayedSongId == -1){
            return;
        }else{
            System.out.println(mostPlayedSongId);
        }
    }
}


public class SongSystemClient{
    public static void main(String[] args) {
        SongSystem system = new SongSystem();
        system.addSong(1, "I am not afraid");
        system.addSong(2, "Spacebound");
        system.addSong(2, "Raanjhna");

        system.playSong(5, 1);
        system.playSong(1, 1);
        system.playSong(2, 2);
        system.playSong(2, 2);
        system.playSong(2, 2);
        system.playSong(2, 3);

        system.printAnalytics();
        system.getLastNFavouriteSongs(2);

    }
}