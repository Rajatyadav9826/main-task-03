#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movie {
public:
    Movie(string title, string genre, string releaseDate) {
        this->title = title;
        this->genre = genre;
        this->releaseDate = releaseDate;
    }
    string title;
    string genre;
    string releaseDate;
    vector<string> showtimes;
};

class Theater {
public:
    Theater(string name, string location) {
        this->name = name;
        this->location = location;
    }
    void add_movie(Movie movie) {
        movies.push_back(movie);
        cout << "Movie added to theater." << endl;
    }
    void list_movies() {
        cout << "Movies currently showing at " << name << ":" << endl;
        for (int i = 0; i < movies.size(); i++) {
            cout << i+1 << ". " << movies[i].title << endl;
        }
    }
    Movie get_movie(int index) {
        return movies[index];
    }
private:
    string name;
    string location;
    vector<Movie> movies;
};

class Booking {
public:
    Booking(Movie movie, string showtime, int numTickets, float totalCost) {
        this->movie = movie;
        this->showtime = showtime;
        this->numTickets = numTickets;
        this->totalCost = totalCost;
    }
    Movie movie;
    string showtime;
    int numTickets;
    float totalCost;
};

void book_ticket(Theater theater, vector<Booking>& bookings) {
    theater.list_movies();
    int movieIndex;
    cout << "Select a movie: ";
    cin >> movieIndex;
    Movie movie = theater.get_movie(movieIndex-1);
    cout << "Showtimes for " << movie.title << ":" << endl;
    for (int i = 0; i < movie.showtimes.size(); i++) {
        cout << i+1 << ". " << movie.showtimes[i] << endl;
    }
    int showtimeIndex;
    cout << "Select a showtime: ";
    cin >> showtimeIndex;
    string showtime = movie.showtimes[showtimeIndex-1];
    int numTickets;
    cout << "Enter number of tickets: ";
    cin >> numTickets;
    if (numTickets <= 0) {
        cout << "Invalid number of tickets." << endl;
        return;
    }
    float ticketPrice = 10.0; // assume all tickets cost $10
    float totalCost = numTickets * ticketPrice;
    Booking booking(movie, showtime, numTickets, totalCost);
    bookings.push_back(booking);
    cout << "Booking complete. Total cost: $" << totalCost << endl;
}

void cancel_ticket(vector<Booking>& bookings) {
    if (bookings.empty()) {
        cout << "No bookings to cancel." << endl;
        return;
    }
    cout << "Enter booking number to cancel: ";
    int bookingIndex;
    cin >> bookingIndex;
    if (bookingIndex < 1 || bookingIndex > bookings.size()) {
        cout << "Invalid booking number." << endl;
        return;
    }
    Booking booking = bookings[bookingIndex-1];
    bookings.erase(bookings.begin() + bookingIndex-1);
    cout << "Booking cancelled. Refund amount: $" << booking.totalCost << endl;
}

void list_bookings(vector<Booking> bookings) {
    if (bookings.empty()) {
        cout << "No bookings to show." << endl;
        return;
    }
    cout << "Current bookings:" << endl;
