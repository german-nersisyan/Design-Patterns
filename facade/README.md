# 🏙️ Smart City Management System with facade pattern

This project is a simulation of a **Smart City Management System**. The system integrates multiple subsystems for efficient city management, including traffic management, surveillance, energy monitoring, and waste management. The code demonstrates how these subsystems can be controlled and optimized via a facade design pattern, which simplifies interaction with complex systems.

## Overview

The system consists of several subsystems:
- **Traffic Management**: Handles traffic lights, incident reporting, congestion detection, and vehicle flow management.
- **Surveillance System**: Monitors surveillance cameras, activates security alarms, runs facial recognition, and detects suspicious activity.
- **Energy Monitoring**: Tracks and optimizes energy consumption, balances the energy grid, and manages renewable energy sources.
- **Waste Management**: Monitors waste bins, dispatches waste collection trucks, optimizes collection routes, and tracks recyclable waste.

The **Facade** pattern is used to provide a simplified interface for interacting with all these subsystems, enabling the system to operate efficiently in a smart city environment.

## Classes:

- **TrafficManagement**: Manages traffic-related operations, such as controlling traffic lights, reporting incidents, detecting congestion, and prioritizing emergency vehicles.
  
- **SurveillanceSystem**: Manages security-related operations like monitoring surveillance cameras, activating alarms, running facial recognition, detecting suspicious activity, and sending real-time alerts.

- **EnergyMonitoring**: Tracks and optimizes energy usage, manages renewable energy sources, and balances the energy grid to integrate renewable energy.

- **WasteManagement**: Monitors and optimizes waste collection processes, including tracking IoT-enabled bins, dispatching waste collection trucks, and tracking recyclable waste.

- **SmartCityFacade**: Provides a simplified interface to interact with the different subsystems. It consolidates the functionality of the traffic, surveillance, energy, and waste management systems, making it easy to control them as a whole.