class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        """
        Determine if a planet can destroy all asteroids by absorbing their mass.
      
        The planet starts with initial mass and can destroy asteroids with mass <= planet's current mass.
        After destroying an asteroid, the planet absorbs its mass.
      
        Args:
            mass: Initial mass of the planet
            asteroids: List of asteroid masses
          
        Returns:
            True if all asteroids can be destroyed, False otherwise
        """
        # Sort asteroids in ascending order to tackle smaller ones first
        # This greedy approach maximizes the planet's growth potential
        asteroids.sort()
      
        # Iterate through each asteroid in ascending order
        for asteroid_mass in asteroids:
            # Check if current planet mass is sufficient to destroy this asteroid
            if mass < asteroid_mass:
                # Planet cannot destroy this asteroid, mission fails
                return False
          
            # Absorb the destroyed asteroid's mass into the planet
            mass += asteroid_mass
      
        # All asteroids successfully destroyed
        return True