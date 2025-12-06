# ❄️ Christmas Movie Database Observer Pattern

This project demonstrates the **Observer design pattern** using a Christmas movie database. The Observer pattern is used to notify interested parties (observers) whenever a new Christmas movie is added to the database.

## Overview

In this implementation:

- **MovieDatabase** is the **Subject** that maintains a list of movies and notifies observers whenever a new movie is added.
- **Viewer** is the **Observer** that receives notifications when a new movie is added to the database.
- The program simulates a movie database where viewers (users) can subscribe to receive notifications about new movies being added.