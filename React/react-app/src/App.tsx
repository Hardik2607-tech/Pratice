import { useState } from "react";

function getStrength(password: string) {
  if (!password) {
    return { score: 0, label: "" };
  }

  let score = 0;

  if (password.length >= 8) score++;
  if (/[A-Z]/.test(password)) score++;
  if (/[0-9]/.test(password)) score++;
  if (/[^A-Za-z0-9]/.test(password)) score++;

  let label = "Weak";

  if (score === 4) {
    label = "Strong";
  } else if (score >= 2) {
    label = "Medium";
  }

  return {
    score: Math.max(score, 1),
    label
  };
}

function PasswordStrengthMeter() {
  const [password, setPassword] = useState("");

  const { score, label } = getStrength(password);

  const colors: { [key: string]: string } = {
    Weak: "red",
    Medium: "orange",
    Strong: "green"
  };

  return (
    <div style={{ maxWidth: 300 }}>
      <input
        type="password"
        value={password}
        onChange={(e) => setPassword(e.target.value)}
        placeholder="Enter password"
        style={{ width: "100%", marginBottom: 8 }}
      />

      <div style={{ display: "flex", gap: 4 }}>
        {[1, 2, 3, 4].map((seg) => (
          <div
            key={seg}
            style={{
              height: 4,
              flex: 1,
              borderRadius: 2,
              background: seg <= score ? colors[label] : "#ddd"
            }}
          />
        ))}
      </div>

      {label && (
        <p style={{ color: colors[label], marginTop: 6 }}>
          {label} password
        </p>
      )}
    </div>
  );
}

export default PasswordStrengthMeter;