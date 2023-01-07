const draggable = document.getElementById("myObject");
const setStatus = (str) =>
  (document.getElementById("status").textContent = str);

let didDrag = false;
let dragOrigin;
let origPos;

draggable.addEventListener("pointerdown", (evt) => {
  evt.target.setPointerCapture(evt.pointerId);
  dragOrigin = { x: evt.clientX, y: evt.clientY };
  const { left, top } = draggable.getBoundingClientRect();
  origPos = { left, top };
  didDrag = false;
});
draggable.addEventListener("pointermove", (evt) => {
  if (dragOrigin) {
    didDrag = true;
    const deltaX = evt.clientX - dragOrigin.x;
    const deltaY = evt.clientY - dragOrigin.y;
    draggable.style.left = `${origPos.left + deltaX}px`;
    draggable.style.top = `${origPos.top + deltaY}px`;
    setStatus("dragging...");
  }
});
draggable.addEventListener("pointerup", (evt) => {
  dragOrigin = undefined;
  if (didDrag) {
    setStatus("Dropped!");
  } else {
    setStatus("Clicked!");
  }
});
window.addEventListener("keydown", (evt) => {
  if (evt.key === "Escape") {
    dragOrigin = undefined;
    draggable.style.left = `${origPos.left}px`;
    draggable.style.top = `${origPos.top}px`;
    setStatus("Cancelled!");
  }
});
