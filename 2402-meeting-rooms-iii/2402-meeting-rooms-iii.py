class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        # Sort meetings by start time
        meetings.sort()
      
        # Min heap to track busy rooms: (end_time, room_number)
        busy_rooms = []
      
        # Min heap to track available rooms by room number
        available_rooms = list(range(n))
        heapify(available_rooms)
      
        # Counter for number of meetings held in each room
        meeting_count = [0] * n
      
        # Process each meeting
        for start_time, end_time in meetings:
            # Free up rooms that have finished their meetings
            while busy_rooms and busy_rooms[0][0] <= start_time:
                freed_room = heappop(busy_rooms)[1]
                heappush(available_rooms, freed_room)
          
            # If there's an available room, use it
            if available_rooms:
                room_id = heappop(available_rooms)
                meeting_count[room_id] += 1
                heappush(busy_rooms, (end_time, room_id))
            else:
                # No available rooms, wait for the earliest room to finish
                earliest_end_time, room_id = heappop(busy_rooms)
                meeting_count[room_id] += 1
                # Schedule meeting right after current meeting ends
                # Duration is (end_time - start_time)
                new_end_time = earliest_end_time + (end_time - start_time)
                heappush(busy_rooms, (new_end_time, room_id))
      
        # Find the room with the most meetings (smallest index if tie)
        most_used_room = 0
        for room_id, count in enumerate(meeting_count):
            if meeting_count[most_used_room] < count:
                most_used_room = room_id
      
        return most_used_room