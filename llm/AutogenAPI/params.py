from pydantic import BaseModel

class WorkflowParameters(BaseModel):
    youtube_video_id: str