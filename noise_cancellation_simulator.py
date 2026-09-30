import math
import random

class NoiseCancel:
    """Simplified Active Noise Cancellation (ANC) Simulator"""
    
    def __init__(self, sample_rate=44100):
        self.sample_rate = sample_rate
        self.noise_profile = {}
    
    def generate_sine_wave(self, frequency, amplitude, duration):
        """Generate a sine wave at given frequency"""
        samples = []
        num_samples = int(self.sample_rate * duration)
        for i in range(num_samples):
            t = i / self.sample_rate
            value = amplitude * math.sin(2 * math.pi * frequency * t)
            samples.append(value)
        return samples
    
    def generate_ambient_noise(self, duration):
        """Simulate ambient noise (random frequencies)"""
        noise = []
        num_samples = int(self.sample_rate * duration)
        for i in range(num_samples):
            # Simulate environmental noise with random low frequencies
            noise.append(random.uniform(-0.1, 0.1))
        return noise
    
    def analyze_frequency(self, signal):
        """Analyze dominant frequency in signal"""
        freq_sum = 0
        for sample in signal:
            freq_sum += abs(sample)
        return freq_sum / len(signal) if signal else 0
    
    def generate_inverse_wave(self, signal, dampening=0.9):
        """Generate inverse waveform to cancel noise"""
        return [-sample * dampening for sample in signal]
    
    def mix_signals(self, signal1, signal2):
        """Combine two signals"""
        return [s1 + s2 for s1, s2 in zip(signal1, signal2)]
    
    def calculate_noise_reduction(self, original, after_anc):
        """Calculate noise reduction percentage"""
        original_power = sum(abs(s) for s in original)
        after_power = sum(abs(s) for s in after_anc)
        
        if original_power == 0:
            return 0
        reduction = ((original_power - after_power) / original_power) * 100
        return max(0, reduction)
    
    def apply_noise_cancellation(self, external_noise, internal_signal, anc_strength=0.8):
        """Apply ANC algorithm"""
        # Step 1: Analyze external noise
        noise_level = self.analyze_frequency(external_noise)
        
        # Step 2: Generate inverse wave to cancel noise
        inverse = self.generate_inverse_wave(external_noise, anc_strength)
        
        # Step 3: Mix inverse wave with internal signal
        result = self.mix_signals(internal_signal, inverse)
        
        # Step 4: Calculate effectiveness
        reduction = self.calculate_noise_reduction(external_noise, result)
        
        return {
            'result_signal': result,
            'noise_level': noise_level,
            'reduction_percentage': reduction,
            'anc_active': True
        }

# Main Demo
if __name__ == "__main__":
    anc = NoiseCancel()
    
    print("=" * 60)
    print("Apple AirPods-Inspired Noise Cancellation Simulator")
    print("=" * 60)
    
    # Simulate scenario
    duration = 0.1  # 100ms audio sample
    
    # Generate ambient noise (traffic, background noise)
    print("\n[1] Generating ambient noise (traffic sound)...")
    ambient_noise = anc.generate_ambient_noise(duration)
    print(f"    Ambient noise level: {anc.analyze_frequency(ambient_noise):.4f}")
    
    # Generate internal audio (music/call)
    print("\n[2] Generating internal signal (user audio)...")
    user_audio = anc.generate_sine_wave(frequency=440, amplitude=0.5, duration=duration)
    print(f"    User audio frequency: 440 Hz")
    
    # Mix signals (what AirPod mic hears without ANC)
    print("\n[3] Without ANC (Raw mixed signal)...")
    mixed_raw = anc.mix_signals(ambient_noise, user_audio)
    raw_noise_level = anc.analyze_frequency(mixed_raw)
    print(f"    Mixed signal noise level: {raw_noise_level:.4f}")
    
    # Apply noise cancellation
    print("\n[4] Applying Active Noise Cancellation...")
    result = anc.apply_noise_cancellation(ambient_noise, user_audio, anc_strength=0.85)
    
    print(f"    Noise level after ANC: {anc.analyze_frequency(result['result_signal']):.4f}")
    print(f"    ✓ Noise reduction: {result['reduction_percentage']:.2f}%")
    print(f"    ✓ ANC Status: {'ACTIVE' if result['anc_active'] else 'OFF'}")
    
    print("\n" + "=" * 60)
    print("Summary:")
    print(f"  Before ANC: {raw_noise_level:.4f}")
    print(f"  After ANC:  {anc.analyze_frequency(result['result_signal']):.4f}")
    print(f"  Improvement: {result['reduction_percentage']:.2f}%")
    print("=" * 60)
